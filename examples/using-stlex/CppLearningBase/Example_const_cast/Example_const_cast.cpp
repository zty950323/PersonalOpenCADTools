///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

class A {
 public:
  const double i = 5.0;
  const int j = 10;
  const string m_s = "Test String.";
  float f = 2.0f;
};

int main() {
  A a;
  cout << a.i << '\t' << a.j << '\t' << a.m_s << endl;
  string& p_str = const_cast<string&>(a.m_s);
  p_str = "New Test String!.";
  cout << a.i << '\t' << a.j << '\t' << a.m_s << endl;
  cout << p_str << endl;
  string* ps = const_cast<string*>(&a.m_s);
  *ps = "Point Test String";
  cout << a.i << '\t' << a.j << '\t' << a.m_s << endl;
  cout << ps << '\t' << *ps << endl;
  // int& p_i = const_cast<int&>(a.i); //
  // 不允许修改基础类型的const，只能改类型限定符 p_i = 200;

  const A ca;
  A& pa = const_cast<A&>(ca);
  pa.f = 30.0f;
  cout << ca.i << '\t' << ca.j << '\t' << ca.m_s << '\t' << ca.f << endl;
  cout << pa.i << '\t' << pa.j << '\t' << pa.m_s << '\t' << pa.f << endl;
}