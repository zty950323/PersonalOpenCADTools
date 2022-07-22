
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

// using capacity.
void TzListCapacityCase01() {
  list<int> v1;
  for (int i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  printList(v1);
  if (v1.empty()) {
    cout << "v1 is null" << endl;
  } else {
    cout << "v1 is not null" << endl;
    cout << "v1's max_size = " << v1.max_size() << endl;
    cout << "v1's size = " << v1.size() << endl;
  }

  // Resize re specifies the size. If the specified size is larger,
  // the new location is filled with 0 by default.
  // You can replace the default filling with the overloaded version
  v1.resize(15, 10);
  printList(v1);

  // Resize re specifies the size. If the specified size is smaller,
  // the excess elements will be deleted
  v1.resize(5);
  printList(v1);
}

// other use ways.
void TzListCapacityCase02() {
  // using empty()
  // empty() returns true if the list is empty, otherwise false.
  std::cout << std::boolalpha;
  std::list<int> numbers;
  std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

  numbers.push_back(42);
  std::cout << "After adding elements, numbers.empty(): " << numbers.empty()
            << '\n';

  // using size()
  // size() returns the number of elements in the list.
  // size() is a member function of the list class.
  // size() is a non-const member function.
  std::list<int> nums{1, 3, 5, 7};
  std::cout << "nums contains " << nums.size() << " elements.\n";

  // using max_size()
  // The max_size() function returns the maximum number of
  // elements that can be stored in the list.
  std::list<char> s;
  std::cout << "Maximum size of a 'list' is " << s.max_size() << "\n";

  // using capacity()
  // capacity() returns the number of elements that the
  // container has currently allocated space for.
  // capacity() does not change the size of the container.
  int sz = 200;
  std::list<int> v1;

  auto cap = v1.max_size();
  std::cout << "initial capacity=" << cap << '\n';

  for (int n = 0; n < sz; ++n) {
    v1.push_back(n);
    if (cap != v1.max_size()) {
      cap = v1.max_size();
      std::cout << "new max_size=" << cap << '\n';
    }
  }

  std::cout << "final size=" << v1.size() << '\n';
  std::cout << "final max_size=" << v1.max_size() << '\n';

  // using shrink_to_fit()
  // shrink_to_fit() is a member function of list class.
  // shrink_to_fit() is used to reduce the capacity of
  // the list to the actual size of the list.
  // shrink_to_fit() is useful when you know that the
  // list will not be resized in the future.
  std::list<int> v;
  std::cout << "Default-constructed max_size is " << v.max_size() << '\n';
  v.resize(100);
  std::cout << "Capacity of a 100-element list is " << v.max_size() << '\n';
  v.resize(50);
  std::cout << "Capacity after resize(50) is " << v.max_size() << '\n';
  v.clear();
  std::cout << "Capacity after clear() is " << v.max_size() << '\n';
  for (int i = 1000; i < 1300; ++i) v.push_back(i);
  std::cout << "Capacity after adding 300 elements is " << v.max_size() << '\n';

  // using resize()
  // resize() is a member function of list class.
  // resize() is used to change the size of the list.
  // resize() is useful when you know that the list will
  // not be resized in the future.
  std::list<int> c = {1, 2, 3};
  std::cout << "The list holds: ";
  for (auto& el : c) std::cout << el << ' ';
  std::cout << '\n';
  c.resize(5);
  std::cout << "After resize up to 5: ";
  for (auto& el : c) std::cout << el << ' ';
  std::cout << '\n';
  c.resize(2);
  std::cout << "After resize down to 2: ";
  for (auto& el : c) std::cout << el << ' ';
  std::cout << '\n';
}

int main() {
  TzListCapacityCase01();
  TzListCapacityCase02();
  system("pause");
  return 0;
}
