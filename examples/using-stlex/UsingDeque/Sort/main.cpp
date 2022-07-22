
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <deque>
#include <iostream>

using std::cout;
using std::deque;
using std::endl;

void printDeque(const deque<int>& d) {
  for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void TzDequeSortCase01() {
  deque<int> d;
  d.push_back(10);
  d.push_back(20);
  d.push_front(100);
  d.push_front(200);
  printDeque(d);
  sort(d.begin(), d.end());
  printDeque(d);
}

int main(int argc, char* argv[]) {
  TzDequeSortCase01();

  system("pause");
  return 0;
}
