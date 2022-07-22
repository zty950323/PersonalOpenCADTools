# CMake generated Testfile for 
# Source directory: D:/Projects/TZOpenTools/DesignPattern/code/Create/Builder
# Build directory: D:/Projects/TZOpenTools/examples/DesignPatternProject/code/Create/Builder
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Builder "D:/Projects/TZOpenTools/DesignPattern/run/Debug/Builder.exe")
  set_tests_properties(Builder PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Create/Builder/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Create/Builder/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Builder "D:/Projects/TZOpenTools/DesignPattern/run/Release/Builder.exe")
  set_tests_properties(Builder PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Create/Builder/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Create/Builder/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Builder "D:/Projects/TZOpenTools/DesignPattern/run/MinSizeRel/Builder.exe")
  set_tests_properties(Builder PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Create/Builder/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Create/Builder/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Builder "D:/Projects/TZOpenTools/DesignPattern/run/RelWithDebInfo/Builder.exe")
  set_tests_properties(Builder PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Create/Builder/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Create/Builder/CMakeLists.txt;0;")
else()
  add_test(Builder NOT_AVAILABLE)
endif()
