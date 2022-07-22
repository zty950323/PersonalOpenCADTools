# CMake generated Testfile for 
# Source directory: D:/Projects/TZOpenTools/DesignPattern/code/Struct/Bridge
# Build directory: D:/Projects/TZOpenTools/examples/DesignPatternProject/code/Struct/Bridge
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Bridge "D:/Projects/TZOpenTools/DesignPattern/run/Debug/Bridge.exe")
  set_tests_properties(Bridge PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Struct/Bridge/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Struct/Bridge/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Bridge "D:/Projects/TZOpenTools/DesignPattern/run/Release/Bridge.exe")
  set_tests_properties(Bridge PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Struct/Bridge/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Struct/Bridge/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Bridge "D:/Projects/TZOpenTools/DesignPattern/run/MinSizeRel/Bridge.exe")
  set_tests_properties(Bridge PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Struct/Bridge/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Struct/Bridge/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Bridge "D:/Projects/TZOpenTools/DesignPattern/run/RelWithDebInfo/Bridge.exe")
  set_tests_properties(Bridge PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Struct/Bridge/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Struct/Bridge/CMakeLists.txt;0;")
else()
  add_test(Bridge NOT_AVAILABLE)
endif()
