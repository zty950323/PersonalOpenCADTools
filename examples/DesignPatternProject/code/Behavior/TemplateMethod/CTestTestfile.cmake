# CMake generated Testfile for 
# Source directory: D:/Projects/TZOpenTools/DesignPattern/code/Behavior/TemplateMethod
# Build directory: D:/Projects/TZOpenTools/examples/DesignPatternProject/code/Behavior/TemplateMethod
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(TemplateMethod "D:/Projects/TZOpenTools/DesignPattern/run/Debug/TemplateMethod.exe")
  set_tests_properties(TemplateMethod PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Behavior/TemplateMethod/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Behavior/TemplateMethod/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(TemplateMethod "D:/Projects/TZOpenTools/DesignPattern/run/Release/TemplateMethod.exe")
  set_tests_properties(TemplateMethod PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Behavior/TemplateMethod/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Behavior/TemplateMethod/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(TemplateMethod "D:/Projects/TZOpenTools/DesignPattern/run/MinSizeRel/TemplateMethod.exe")
  set_tests_properties(TemplateMethod PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Behavior/TemplateMethod/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Behavior/TemplateMethod/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(TemplateMethod "D:/Projects/TZOpenTools/DesignPattern/run/RelWithDebInfo/TemplateMethod.exe")
  set_tests_properties(TemplateMethod PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Behavior/TemplateMethod/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Behavior/TemplateMethod/CMakeLists.txt;0;")
else()
  add_test(TemplateMethod NOT_AVAILABLE)
endif()
