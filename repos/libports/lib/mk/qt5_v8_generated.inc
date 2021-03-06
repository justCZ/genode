QT_DEFINES += -DQT_NO_LIBUDEV -DQT_NO_XCB -DQT_NO_XKBCOMMON -DQT_BUILD_V8_LIB -DQT_BUILDING_QT -DQT_NO_CAST_TO_ASCII -DQT_ASCII_CAST_WARNINGS -DQT_MOC_COMPAT -DQT_USE_QSTRINGBUILDER -DQT_DEPRECATED_WARNINGS -DQT_DISABLE_DEPRECATED_BEFORE=0x050000 -DV8_SHARED -DBUILDING_V8_SHARED -DENABLE_DEBUGGER_SUPPORT -DENABLE_VMSTATE_TRACKING -DENABLE_LOGGING_AND_PROFILING -DNDEBUG -DV8_TARGET_ARCH_X64 -DQT_NO_EXCEPTIONS -DQT_NO_DEBUG

QT_INCPATH += \
  qtbase/mkspecs/genode-g++ \
  qtjsbackend/include \
  qtjsbackend/include/QtV8 \
  qtjsbackend/include/QtV8/5.1.0 \
  qtjsbackend/include/QtV8/5.1.0/QtV8 \
  qtjsbackend/src/3rdparty/v8/src \
  qtjsbackend/src/v8 \

QT_SOURCES += \
  accessors.cc \
  allocation.cc \
  api.cc \
  assembler.cc \
  ast.cc \
  atomicops_internals_x86_gcc.cc \
  bignum.cc \
  bignum-dtoa.cc \
  bootstrapper.cc \
  builtins.cc \
  cached-powers.cc \
  checks.cc \
  circular-queue.cc \
  code-stubs.cc \
  codegen.cc \
  compilation-cache.cc \
  compiler.cc \
  contexts.cc \
  conversions.cc \
  counters.cc \
  cpu-profiler.cc \
  data-flow.cc \
  date.cc \
  dateparser.cc \
  debug-agent.cc \
  debug.cc \
  deoptimizer.cc \
  disassembler.cc \
  diy-fp.cc \
  dtoa.cc \
  elements.cc \
  elements-kind.cc \
  execution.cc \
  factory.cc \
  flags.cc \
  frames.cc \
  full-codegen.cc \
  func-name-inferrer.cc \
  gdb-jit.cc \
  global-handles.cc \
  fast-dtoa.cc \
  fixed-dtoa.cc \
  handles.cc \
  heap-profiler.cc \
  heap.cc \
  hydrogen.cc \
  hydrogen-instructions.cc \
  ic.cc \
  incremental-marking.cc \
  inspector.cc \
  interface.cc \
  interpreter-irregexp.cc \
  isolate.cc \
  jsregexp.cc \
  lithium-allocator.cc \
  lithium.cc \
  liveedit.cc \
  liveobjectlist.cc \
  log-utils.cc \
  log.cc \
  mark-compact.cc \
  messages.cc \
  objects.cc \
  objects-printer.cc \
  objects-visiting.cc \
  once.cc \
  optimizing-compiler-thread.cc \
  parser.cc \
  preparser.cc \
  preparse-data.cc \
  profile-generator.cc \
  property.cc \
  regexp-macro-assembler-irregexp.cc \
  regexp-macro-assembler.cc \
  regexp-stack.cc \
  rewriter.cc \
  runtime.cc \
  runtime-profiler.cc \
  safepoint-table.cc \
  scanner.cc \
  scanner-character-streams.cc \
  scopeinfo.cc \
  scopes.cc \
  serialize.cc \
  snapshot-common.cc \
  spaces.cc \
  string-search.cc \
  string-stream.cc \
  strtod.cc \
  stub-cache.cc \
  token.cc \
  transitions.cc \
  type-info.cc \
  unicode.cc \
  utils.cc \
  v8-counters.cc \
  v8.cc \
  v8conversions.cc \
  v8threads.cc \
  v8utils.cc \
  variables.cc \
  version.cc \
  store-buffer.cc \
  zone.cc \
  externalize-string-extension.cc \
  gc-extension.cc \
  statistics-extension.cc \
  assembler-x64.cc \
  builtins-x64.cc \
  code-stubs-x64.cc \
  codegen-x64.cc \
  cpu-x64.cc \
  debug-x64.cc \
  deoptimizer-x64.cc \
  disasm-x64.cc \
  frames-x64.cc \
  full-codegen-x64.cc \
  ic-x64.cc \
  lithium-codegen-x64.cc \
  lithium-gap-resolver-x64.cc \
  lithium-x64.cc \
  macro-assembler-x64.cc \
  regexp-macro-assembler-x64.cc \
  stub-cache-x64.cc \
  platform-genode.cc \
  platform-posix.cc \
  objects-debug.cc \
  prettyprinter.cc \
  regexp-macro-assembler-tracer.cc \
  snapshot-empty.cc \
  libraries.cpp \
  experimental-libraries.cpp

QT_VPATH += \
  qtjsbackend/src/3rdparty/v8/src \
  qtjsbackend/src/3rdparty/v8/src/extensions \
  qtjsbackend/src/3rdparty/v8/src/x64 \

# some source files need to be generated by moc from other source/header files before
# they get #included again by the original source file in the compiling stage

# source files generated from existing header files ('moc_%.cpp: %.h' rule in import-qt5.inc)
# extracted from 'compiler_moc_header_make_all' target


# source files generated from existing source files ('%.moc: %.cpp' rule in import-qt5.inc)
# extracted from 'compiler_moc_source_make_all' rule


