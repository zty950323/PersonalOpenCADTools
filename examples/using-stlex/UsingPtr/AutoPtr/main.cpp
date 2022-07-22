
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description: This is a case for using auto_ptr(discard in c++11).
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

#if !_HAS_CXX20

void useAutoPtrCase01() {
  // no.1 method for initializing auto_ptr.
  std::auto_ptr<int> ap1(new int(8));
  // no.2 method for initializing auto_ptr.
  std::auto_ptr<int> ap2;
  ap2.reset(new int(8));
}

void useAutoPtrCase02() {
  // test copy constructor.
  std::auto_ptr<int> ap1(new int(8));
  std::auto_ptr<int> ap2(ap1);
  if (ap1.get() != NULL) {
    std::cout << "ap1 is not empty." << std::endl;
  } else {
    std::cout << "ap1 is empty." << std::endl;
  }
  if (ap2.get() != NULL) {
    std::cout << "ap2 is not empty." << std::endl;
  } else {
    std::cout << "ap2 is empty." << std::endl;
  }

  // test for set constructor.
  std::auto_ptr<int> ap3(new int(8));
  std::auto_ptr<int> ap4;
  ap4 = ap3;
  if (ap3.get() != NULL) {
    std::cout << "ap3 is not empty." << std::endl;
  } else {
    std::cout << "ap3 is empty." << std::endl;
  }

  if (ap4.get() != NULL) {
    std::cout << "ap4 is not empty." << std::endl;
  } else {
    std::cout << "ap4 is empty." << std::endl;
  }
}

#endif

int main(int argc, char* argv[]) {
#if !_HAS_CXX20
  useAutoPtrCase01();
  useAutoPtrCase02();
#endif
  system("pause");
  return 0;
}
