# CMake generated Testfile for 
# Source directory: D:/Projects/TZOpenTools/DesignPattern/code/Create/Singleton_Practise
# Build directory: D:/Projects/TZOpenTools/examples/DesignPatternProject/code/Create/Singleton_Practise
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Singleton_Practise "D:/Projects/TZOpenTools/DesignPattern/run/Debug/Singleton_Practise.exe")
  set_tests_properties(Singleton_Practise PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Create/Singleton_Practise/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Create/Singleton_Practise/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Singleton_Practise "D:/Projects/TZOpenTools/DesignPattern/run/Release/Singleton_Practise.exe")
  set_tests_properties(Singleton_Practise PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Create/Singleton_Practise/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Create/Singleton_Practise/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Singleton_Practise "D:/Projects/TZOpenTools/DesignPattern/run/MinSizeRel/Singleton_Practise.exe")
  set_tests_properties(Singleton_Practise PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Create/Singleton_Practise/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Create/Singleton_Practise/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Singleton_Practise "D:/Projects/TZOpenTools/DesignPattern/run/RelWithDebInfo/Singleton_Practise.exe")
  set_tests_properties(Singleton_Practise PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Create/Singleton_Practise/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Create/Singleton_Practise/CMakeLists.txt;0;")
else()
  add_test(Singleton_Practise NOT_AVAILABLE)
endif()
