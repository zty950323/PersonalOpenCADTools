# CMake generated Testfile for 
# Source directory: D:/Projects/TZOpenTools/DesignPattern/code/Create/Prototype
# Build directory: D:/Projects/TZOpenTools/examples/DesignPatternProject/code/Create/Prototype
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Prototype "D:/Projects/TZOpenTools/DesignPattern/run/Debug/Prototype.exe")
  set_tests_properties(Prototype PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Create/Prototype/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Create/Prototype/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Prototype "D:/Projects/TZOpenTools/DesignPattern/run/Release/Prototype.exe")
  set_tests_properties(Prototype PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Create/Prototype/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Create/Prototype/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Prototype "D:/Projects/TZOpenTools/DesignPattern/run/MinSizeRel/Prototype.exe")
  set_tests_properties(Prototype PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Create/Prototype/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Create/Prototype/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Prototype "D:/Projects/TZOpenTools/DesignPattern/run/RelWithDebInfo/Prototype.exe")
  set_tests_properties(Prototype PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Create/Prototype/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Create/Prototype/CMakeLists.txt;0;")
else()
  add_test(Prototype NOT_AVAILABLE)
endif()
