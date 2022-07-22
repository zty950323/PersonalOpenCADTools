# CMake generated Testfile for 
# Source directory: D:/Projects/TZOpenTools/DesignPattern/Template/Create/SingletonTemplate
# Build directory: D:/Projects/TZOpenTools/examples/DesignPatternProject/Template/Create/SingletonTemplate
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(SingletonTemplate "D:/Projects/TZOpenTools/DesignPattern/run/Debug/SingletonTemplate.exe")
  set_tests_properties(SingletonTemplate PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/Template/Create/SingletonTemplate/CMakeLists.txt;7;add_test;D:/Projects/TZOpenTools/DesignPattern/Template/Create/SingletonTemplate/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(SingletonTemplate "D:/Projects/TZOpenTools/DesignPattern/run/Release/SingletonTemplate.exe")
  set_tests_properties(SingletonTemplate PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/Template/Create/SingletonTemplate/CMakeLists.txt;7;add_test;D:/Projects/TZOpenTools/DesignPattern/Template/Create/SingletonTemplate/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(SingletonTemplate "D:/Projects/TZOpenTools/DesignPattern/run/MinSizeRel/SingletonTemplate.exe")
  set_tests_properties(SingletonTemplate PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/Template/Create/SingletonTemplate/CMakeLists.txt;7;add_test;D:/Projects/TZOpenTools/DesignPattern/Template/Create/SingletonTemplate/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(SingletonTemplate "D:/Projects/TZOpenTools/DesignPattern/run/RelWithDebInfo/SingletonTemplate.exe")
  set_tests_properties(SingletonTemplate PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/Template/Create/SingletonTemplate/CMakeLists.txt;7;add_test;D:/Projects/TZOpenTools/DesignPattern/Template/Create/SingletonTemplate/CMakeLists.txt;0;")
else()
  add_test(SingletonTemplate NOT_AVAILABLE)
endif()
