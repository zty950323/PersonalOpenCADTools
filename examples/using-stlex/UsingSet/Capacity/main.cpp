
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;

void printSet(const set<int>& s) {
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void TzSetCapacityCase01() {
  set<int> s1;
  s1.insert(10);
  s1.insert(30);
  s1.insert(20);
  s1.insert(40);
  if (s1.empty()) {
    cout << "s1 is null." << endl;
  } else {
    cout << "s1 is not null." << endl;
    cout << "the size of s1 is: " << s1.size() << endl;
  }
}

void TzSetCapacityCase02() {
  set<int> s1;
  s1.insert(10);
  s1.insert(30);
  s1.insert(20);
  s1.insert(40);
  set<int> s2;
  s2.insert(100);
  s2.insert(300);
  s2.insert(200);
  s2.insert(400);
  cout << "before the swap:" << endl;
  printSet(s1);
  printSet(s2);
  cout << endl;
  cout << "after the swap:" << endl;
  s1.swap(s2);
  printSet(s1);
  printSet(s2);
}

int main() {
  TzSetCapacityCase01();
  TzSetCapacityCase02();
  system("pause");
  return 0;
}
