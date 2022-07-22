
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

void TzListStoreDataCase01() {
  list<int> v1;
  for (int i = 0; i < 10; i++) {
    v1.push_back(i);
  }

  // using *it to access the element.
  for (auto it = v1.begin(); it != v1.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "the first element of v1 is： " << v1.front() << endl;
  cout << "the last element of v1 is： " << v1.back() << endl;
}

void TzListStoreDataCase02() {
  std::list<int> numbers{2, 4, 6, 8};
  auto it = numbers.begin();
  std::advance(it, 2);
  std::cout << "Second element: " << *it << '\n';
  it = numbers.begin();
  *it = 5;

  std::cout << "All numbers:";
  for (auto i : numbers) {
    std::cout << ' ' << i;
  }
  std::cout << '\n';
}

// using at() to access the element.
void TzListStoreDataCase03() {
  std::list<int> data = {1, 2, 4, 5, 5, 6};
  // Set element 1
  auto it = data.begin();
  std::advance(it, 2);
  *it = 88;
  // Read element 2
  std::cout << "Element at index 2 has value " << *it << '\n';
  std::cout << "data size = " << data.size() << '\n';
  try {
    // Set element 6
    auto it = data.begin();
    std::advance(it, 4);
    *it = 666;
  } catch (std::out_of_range const& exc) {
    // if the index is out of range, it will throw an exception.
    std::cout << exc.what() << '\n';
  }
  // Print final values
  std::cout << "data:";
  for (int elem : data) std::cout << " " << elem;
  std::cout << '\n';
}

int main(int argc, char* argv[]) {
  TzListStoreDataCase01();
  TzListStoreDataCase02();
  TzListStoreDataCase03();

  system("pause");
  return 0;
}
