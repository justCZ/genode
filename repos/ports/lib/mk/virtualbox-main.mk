include $(REP_DIR)/lib/mk/virtualbox-common.inc

VBOX_CC_OPT += -DVBOX_COM_INPROC_API_CLIENT

LIBS  += stdcxx

SRC_CC += Main/xml/Settings.cpp

SRC_CC += Main/src-all/EventImpl.cpp
SRC_CC += Main/src-all/DisplayResampleImage.cpp
SRC_CC += Main/src-all/DisplayUtils.cpp
SRC_CC += Main/src-all/Global.cpp
SRC_CC += Main/src-all/HashedPw.cpp
SRC_CC += Main/src-all/PCIDeviceAttachmentImpl.cpp
SRC_CC += Main/src-all/ProgressImpl.cpp
SRC_CC += Main/src-all/SharedFolderImpl.cpp
SRC_CC += Main/src-all/VirtualBoxBase.cpp

SRC_CC += Main/src-client/AdditionsFacilityImpl.cpp
SRC_CC += Main/src-client/BusAssignmentManager.cpp
SRC_CC += Main/src-client/ConsoleImpl.cpp
SRC_CC += Main/src-client/ConsoleImpl2.cpp
SRC_CC += Main/src-client/DisplayImpl.cpp
SRC_CC += Main/src-client/GuestImpl.cpp
SRC_CC += Main/src-client/HGCM.cpp
SRC_CC += Main/src-client/HGCMObjects.cpp
SRC_CC += Main/src-client/HGCMThread.cpp
SRC_CC += Main/src-client/KeyboardImpl.cpp
SRC_CC += Main/src-client/MouseImpl.cpp
SRC_CC += Main/src-client/VBoxDriversRegister.cpp
SRC_CC += Main/src-client/VMMDevInterface.cpp
SRC_CC += Main/src-client/SessionImpl.cpp

SRC_CC += Main/src-server/AudioAdapterImpl.cpp
SRC_CC += Main/src-server/BandwidthControlImpl.cpp
SRC_CC += Main/src-server/BandwidthGroupImpl.cpp
SRC_CC += Main/src-server/BIOSSettingsImpl.cpp
SRC_CC += Main/src-server/DHCPServerImpl.cpp
SRC_CC += Main/src-server/GuestOSTypeImpl.cpp
SRC_CC += Main/src-server/MachineImpl.cpp
SRC_CC += Main/src-server/MachineImplCloneVM.cpp
SRC_CC += Main/src-server/MediumAttachmentImpl.cpp
SRC_CC += Main/src-server/MediumImpl.cpp
SRC_CC += Main/src-server/MediumFormatImpl.cpp
SRC_CC += Main/src-server/MediumLock.cpp
SRC_CC += Main/src-server/NATEngineImpl.cpp 
SRC_CC += Main/src-server/NetworkAdapterImpl.cpp
SRC_CC += Main/src-server/NetworkServiceRunner.cpp
SRC_CC += Main/src-server/ParallelPortImpl.cpp
SRC_CC += Main/src-server/SerialPortImpl.cpp
SRC_CC += Main/src-server/SnapshotImpl.cpp
SRC_CC += Main/src-server/StorageControllerImpl.cpp
SRC_CC += Main/src-server/SystemPropertiesImpl.cpp
SRC_CC += Main/src-server/TokenImpl.cpp
SRC_CC += Main/src-server/USBControllerImpl.cpp
SRC_CC += Main/src-server/USBDeviceFilterImpl.cpp
SRC_CC += Main/src-server/USBDeviceFiltersImpl.cpp
SRC_CC += Main/src-server/VirtualBoxImpl.cpp
SRC_CC += Main/src-server/VRDEServerImpl.cpp

SRC_CC += Main/glue/AutoLock.cpp
SRC_CC += Main/glue/EventQueue.cpp
SRC_CC += Main/glue/string.cpp
SRC_CC += Main/glue/xpcom/helpers.cpp

INC_DIR += $(VBOX_DIR)/Main/xml
INC_DIR += $(VBOX_DIR)/Main/include
INC_DIR += $(REP_DIR)/src/virtualbox/frontend
