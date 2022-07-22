# CMake generated Testfile for 
# Source directory: D:/Projects/TZOpenTools/DesignPattern/code/Behavior/State
# Build directory: D:/Projects/TZOpenTools/examples/DesignPatternProject/code/Behavior/State
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(State "D:/Projects/TZOpenTools/DesignPattern/run/Debug/State.exe")
  set_tests_properties(State PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Behavior/State/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Behavior/State/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(State "D:/Projects/TZOpenTools/DesignPattern/run/Release/State.exe")
  set_tests_properties(State PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Behavior/State/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Behavior/State/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(State "D:/Projects/TZOpenTools/DesignPattern/run/MinSizeRel/State.exe")
  set_tests_properties(State PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Behavior/State/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Behavior/State/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(State "D:/Projects/TZOpenTools/DesignPattern/run/RelWithDebInfo/State.exe")
  set_tests_properties(State PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/TZOpenTools/DesignPattern/code/Behavior/State/CMakeLists.txt;5;add_test;D:/Projects/TZOpenTools/DesignPattern/code/Behavior/State/CMakeLists.txt;0;")
else()
  add_test(State NOT_AVAILABLE)
endif()
