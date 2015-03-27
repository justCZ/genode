/*
 * \brief   Hardware-interrupt subsystem
 * \author  Christian Helmuth
 * \date    2008-08-15
 *
 * Open issues:
 *
 * - IRQ thread priority
 * - IRQ sharing
 * - IRQ detachment
 *   - Could be solved by just killing driver process and reclaiming all
 *     resources.
 * - error handling on attachment
 */

/*
 * Copyright (C) 2008-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#include <base/env.h>
#include <base/lock.h>
#include <base/printf.h>
#include <base/thread.h>
#include <base/snprintf.h>
#include <util/avl_tree.h>

#include <irq_session/connection.h>

extern "C" {
#include <dde_kit/interrupt.h>
#include <dde_kit/thread.h>
}

#include "thread.h"
#include "device.h"

using namespace Genode;

class Irq_handler : Dde_kit::Thread, public Avl_node<Irq_handler>
{
	private:

		unsigned       _irq_number;      /* IRQ number */
		char           _thread_name[10];

		void (*_handler)(void *);        /* handler function */
		void (*_init)(void *);           /* thread init function */
		void          *_priv;            /* private handler token */

		bool           _shared;          /* true, if IRQ sharing is supported */
		int            _handle_irq;      /* nested irq disable counter */
		Lock           _lock;            /* synchronize access to counter */

		Genode::Signal_receiver                _sig_rec;
		Genode::Signal_dispatcher<Irq_handler> _irq_dispatcher;

		uint8_t _bus;
		uint8_t _dev;
		uint8_t _func;

		const char * _compose_thread_name(unsigned irq)
		{
			snprintf(_thread_name, sizeof(_thread_name), "irq.%02x", irq);
			return _thread_name;
		}

		void _handle(unsigned)
		{
			/* only call registered handler function, if IRQ is not disabled */
			_lock.lock();
			if (_handle_irq) _handler(_priv);
			_lock.unlock();

			Dde_kit::Device::ack_irq(_bus, _dev, _func);
		}

	public:

		Irq_handler(unsigned irq, void (*handler)(void *), void *priv,
		            void (*init)(void *), bool shared,
		            uint8_t bus, uint8_t dev, uint8_t func)
		:
			Dde_kit::Thread(_compose_thread_name(irq)), _irq_number(irq),
			_handler(handler), _init(init), _priv(priv),
			_shared(shared), _handle_irq(1), _lock(Lock::LOCKED),
			_irq_dispatcher(_sig_rec, *this, &Irq_handler::_handle),
			_bus(bus), _dev(dev), _func(func)
		{
			Dde_kit::Device::enable_irq(_bus, _dev, _func, _irq_dispatcher);

			start();

			/* wait until thread is started */
			Lock::Guard guard(_lock);

			/* initial ack so that we will receive further interrupts */
			Dde_kit::Device::ack_irq(_bus, _dev, _func);

		}

		/** Enable IRQ handling */
		void enable()
		{
			Lock::Guard lock_guard(_lock);
			++_handle_irq;
		}

		/** Disable IRQ handling */
		void disable()
		{
			Lock::Guard lock_guard(_lock);
			--_handle_irq;
		}

		/** Thread entry */
		void entry()
		{
			dde_kit_thread_adopt_myself(_thread_name);

			/* call user init function before doing anything else here */
			if (_init) _init(_priv);

			/* unblock creating thread */
			_lock.unlock();

			while (1) {
				using namespace Genode;

				Signal sig = _sig_rec.wait_for_signal();
				int num    = sig.num();

				Signal_dispatcher_base *dispatcher;
				dispatcher = dynamic_cast<Signal_dispatcher_base *>(sig.context());
				dispatcher->dispatch(num);
			}
		}

		/** AVL node comparison */
		bool higher(Irq_handler *irq_handler) {
			return (_irq_number < irq_handler->_irq_number); }

		/** AVL node lookup */
		Irq_handler *lookup(unsigned irq_number)
		{
			if (irq_number == _irq_number) return this;

			Irq_handler *h = child(_irq_number < irq_number);
			return h ? h->lookup(irq_number) : 0;
		}
};

class Irq_handler_database : public Avl_tree<Irq_handler>
{
	private:

		Lock _lock;

	public:

		Irq_handler *lookup(unsigned irq_number)
		{
			Lock::Guard lock_guard(_lock);

			return first() ? first()->lookup(irq_number) : 0;
		}

		void insert(Irq_handler *h)
		{
			Lock::Guard lock_guard(_lock);

			Avl_tree<Irq_handler>::insert(h);
		}

		void remove(Irq_handler *h)
		{
			Lock::Guard lock_guard(_lock);

			Avl_tree<Irq_handler>::remove(h);
		}
};

static Irq_handler_database *irq_handlers()
{
	static Irq_handler_database _irq_handlers;
	return &_irq_handlers;
}


extern "C" int dde_kit_interrupt_attach(int irq, int shared,
                                        void(*thread_init)(void *),
                                        void(*handler)(void *), void *priv,
                                        uint8_t bus, uint8_t dev, uint8_t func)
{
	Irq_handler *h;

	try {
		h = new (env()->heap()) Irq_handler(irq, handler, priv, thread_init,
		                                    shared, bus, dev, func);
	} catch (...) {
		PERR("allocation failed (size=%zd)", sizeof(*h));
		return -1;
	}

	irq_handlers()->insert(h);

	return 0;
}


extern "C" void dde_kit_interrupt_detach(int irq) {
	PERR("not implemented yet"); }


extern "C" void dde_kit_interrupt_disable(int irq)
{
	Irq_handler *h = irq_handlers()->lookup(irq);

	if (h) h->disable();
}


extern "C" void dde_kit_interrupt_enable(int irq)
{
	Irq_handler *h = irq_handlers()->lookup(irq);

	if (h) h->enable();
}
