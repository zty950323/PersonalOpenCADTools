# CMake generated Testfile for 
# Source directory: D:/Projects/TZOpenTools/DesignPattern/code/Struct/Facade
# Build directory: D:/Projects/TZOpenTools/examples/DesignPatternProject/code/Struct/Facade
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Facade "D:/Projects/TZOpenTools/DesignPattern/run/Debug/Facade.exe")
  set_tests_properties(Facade PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Struct/Facade/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Struct/Facade/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Facade "D:/Projects/TZOpenTools/DesignPattern/run/Release/Facade.exe")
  set_tests_properties(Facade PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Struct/Facade/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Struct/Facade/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Facade "D:/Projects/TZOpenTools/DesignPattern/run/MinSizeRel/Facade.exe")
  set_tests_properties(Facade PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Struct/Facade/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Struct/Facade/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Facade "D:/Projects/TZOpenTools/DesignPattern/run/RelWithDebInfo/Facade.exe")
  set_tests_properties(Facade PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Struct/Facade/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Struct/Facade/CMakeLists.txt;0;")
else()
  add_test(Facade NOT_AVAILABLE)
endif()
