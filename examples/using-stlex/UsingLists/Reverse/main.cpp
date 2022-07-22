
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <cstddef>
#include <iostream>
#include <list>
#include <new>

using std::cout;
using std::endl;
using std::list;

void printList(const list<int>& L) {
  for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list) {
  for (auto& i : list) {
    ostr << " " << i;
  }
  return ostr;
}

bool myCompare(int val1, int val2) { return val1 > val2; }

void TzListReverseCase01() {
  std::list<int> list = {8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::cout << "before: " << list << "\n";
  list.sort();
  std::cout << "ascending: " << list << "\n";
  list.reverse();
  std::cout << "descending: " << list << "\n";
}

void TzListReverseCase02() {
  list<int> L;
  L.push_back(90);
  L.push_back(30);
  L.push_back(20);
  L.push_back(70);
  printList(L);

  // reverse the list.
  L.reverse();
  printList(L);

  // sort the list.
  L.sort();  // default is ascending order.
  printList(L);

  L.sort(myCompare);  // indicate the compare function.
  printList(L);
}

int main(int argc, char* argv[]) {
  TzListReverseCase01();
  TzListReverseCase02();

  system("pause");
  return 0;
}
