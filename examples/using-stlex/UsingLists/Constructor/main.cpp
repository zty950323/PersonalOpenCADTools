
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

// print the list for show.
void printList(const list<int>& v) {
  for (list<int>::const_iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void TzListConstructorCase01() {
  list<int> v1;  // constructor without any param.
  for (int i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  printList(v1);
  // constructor with param with a certain list's start and end.
  list<int> v2(v1.begin(), v1.end());
  printList(v2);
  // constructor with param with range.
  list<int> v3(10, 100);
  printList(v3);
  // constructor with param with a certain list.
  list<int> v4(v3);
  printList(v4);
}

void TzListConstructorCase02() {
  list<int> L1;
  L1.push_back(10);
  L1.push_back(20);
  L1.push_back(30);
  L1.push_back(40);

  printList(L1);

  list<int> L2(L1.begin(), L1.end());
  printList(L2);

  list<int> L3(L2);
  printList(L3);

  list<int> L4(10, 1000);
  printList(L4);

  list<int> L5(L4);
  printList(L5);
}

void TzListConstructorCase03() {
  list<int> c1, c2;
  list<int>::const_iterator cIter;

  c1.push_back(10);
  c1.push_back(20);
  c1.push_back(30);
  c2.push_back(40);
  c2.push_back(50);
  c2.push_back(60);

  cout << "c1 =";
  printList(c1);

  c1.assign(++c2.begin(), c2.end());
  cout << "c1 =";
  printList(c1);

  c1.assign(7, 4);
  cout << "c1 =";
  printList(c1);

  c1.assign({10, 20, 30, 40});
  cout << "c1 =";
  printList(c1);
}

int main(int argc, char* argv[]) {
  TzListConstructorCase01();
  TzListConstructorCase02();
  TzListConstructorCase03();

  system("pause");
  return 0;
}
