# CMake generated Testfile for 
# Source directory: D:/Projects/TZOpenTools/DesignPattern/Template/Behavior/ObserverTemplate
# Build directory: D:/Projects/TZOpenTools/examples/DesignPatternProject/Template/Behavior/ObserverTemplate
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(ObserverTemplate "D:/Projects/TZOpenTools/DesignPattern/run/Debug/ObserverTemplate.exe")
  set_tests_properties(ObserverTemplate PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/Template/Behavior/ObserverTemplate/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/Template/Behavior/ObserverTemplate/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(ObserverTemplate "D:/Projects/TZOpenTools/DesignPattern/run/Release/ObserverTemplate.exe")
  set_tests_properties(ObserverTemplate PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/Template/Behavior/ObserverTemplate/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/Template/Behavior/ObserverTemplate/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(ObserverTemplate "D:/Projects/TZOpenTools/DesignPattern/run/MinSizeRel/ObserverTemplate.exe")
  set_tests_properties(ObserverTemplate PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/Template/Behavior/ObserverTemplate/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/Template/Behavior/ObserverTemplate/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(ObserverTemplate "D:/Projects/TZOpenTools/DesignPattern/run/RelWithDebInfo/ObserverTemplate.exe")
  set_tests_properties(ObserverTemplate PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/Template/Behavior/ObserverTemplate/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/Template/Behavior/ObserverTemplate/CMakeLists.txt;0;")
else()
  add_test(ObserverTemplate NOT_AVAILABLE)
endif()
