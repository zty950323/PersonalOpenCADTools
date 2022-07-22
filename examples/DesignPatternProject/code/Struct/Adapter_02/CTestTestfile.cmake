# CMake generated Testfile for 
# Source directory: D:/Projects/TZOpenTools/DesignPattern/code/Struct/Adapter_02
# Build directory: D:/Projects/TZOpenTools/examples/DesignPatternProject/code/Struct/Adapter_02
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Adapter_02 "D:/Projects/TZOpenTools/DesignPattern/run/Debug/Adapter_02.exe")
  set_tests_properties(Adapter_02 PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Struct/Adapter_02/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Struct/Adapter_02/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Adapter_02 "D:/Projects/TZOpenTools/DesignPattern/run/Release/Adapter_02.exe")
  set_tests_properties(Adapter_02 PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Struct/Adapter_02/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Struct/Adapter_02/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Adapter_02 "D:/Projects/TZOpenTools/DesignPattern/run/MinSizeRel/Adapter_02.exe")
  set_tests_properties(Adapter_02 PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Struct/Adapter_02/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Struct/Adapter_02/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Adapter_02 "D:/Projects/TZOpenTools/DesignPattern/run/RelWithDebInfo/Adapter_02.exe")
  set_tests_properties(Adapter_02 PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Struct/Adapter_02/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Struct/Adapter_02/CMakeLists.txt;0;")
else()
  add_test(Adapter_02 NOT_AVAILABLE)
endif()
