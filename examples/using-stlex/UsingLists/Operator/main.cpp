
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

void printList(const list<int>& v) {
  for (list<int>::const_iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

// operator=
void TzListOperatorCase01() {
  list<int> v1;
  for (int i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  printList(v1);

  list<int> v2;
  v2 = v1;
  printList(v2);

  list<int> v3;
  v3.assign(v1.begin(), v1.end());
  printList(v3);

  list<int> v4;
  v4.assign(10, 100);
  printList(v4);
}

// other operators.
void TzListOperatorCase02() {
  std::list<int> alice{1, 2, 3};
  std::list<int> bob{7, 8, 9, 10};
  std::list<int> eve{1, 2, 3};
  std::cout << std::boolalpha;
  // Compare non equal containers
  std::cout << "alice == bob returns " << (alice == bob) << '\n';
  std::cout << "alice != bob returns " << (alice != bob) << '\n';
  std::cout << "alice <  bob returns " << (alice < bob) << '\n';
  std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
  std::cout << "alice >  bob returns " << (alice > bob) << '\n';
  std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
  std::cout << '\n';

  // Compare equal containers
  std::cout << "alice == eve returns " << (alice == eve) << '\n';
  std::cout << "alice != eve returns " << (alice != eve) << '\n';
  std::cout << "alice <  eve returns " << (alice < eve) << '\n';
  std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
  std::cout << "alice >  eve returns " << (alice > eve) << '\n';
  std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
}

void TzListOperatorCase03() {
  list<int> c1, c2;
  c1.push_back(1);
  c2.push_back(2);

  if (c1 != c2) {
    cout << "Lists not equal." << endl;
  } else {
    cout << "Lists equal." << endl;
  }
}

void TzListOperatorCase04() {
  list<int> c1, c2;
  c1.push_back(1);
  c1.push_back(2);
  c1.push_back(4);
  c2.push_back(1);
  c2.push_back(3);

  if (c1 < c2)
    cout << "List c1 is less than list c2." << endl;
  else
    cout << "List c1 is not less than list c2." << endl;
}

int main() {
  TzListOperatorCase01();
  TzListOperatorCase02();

  system("pause");
  return 0;
}
