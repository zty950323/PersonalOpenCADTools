
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void printVector(const vector<int>& v) {
  for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

// using capacity.
void TzVectorCapacityCase01() {
  vector<int> v1;
  for (int i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  printVector(v1);
  if (v1.empty()) {
    cout << "v1 is null" << endl;
  } else {
    cout << "v1 is not null" << endl;
    cout << "v1's capacity = " << v1.capacity() << endl;
    cout << "v1's size = " << v1.size() << endl;
  }
  // Resize re specifies the size. If the specified size is larger,
  // the new location is filled with 0 by default.
  // You can replace the default filling with the overloaded version
  v1.resize(15, 10);
  printVector(v1);
  // Resize re specifies the size.
  // If the specified size is smaller,
  // the excess elements will be deleted.
  v1.resize(5);
  printVector(v1);
}

// other use ways.
void TzVectorCapacityCase02() {
  // using empty()
  // empty() returns true if the vector is empty, otherwise false.
  std::cout << std::boolalpha;
  std::vector<int> numbers;
  std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
  numbers.push_back(42);
  std::cout << "After adding elements, numbers.empty(): " << numbers.empty()
            << '\n';

  // using size()
  // size() returns the number of elements in the vector.
  // size() is a member function of the vector class.
  // size() is a non-const member function.
  std::vector<int> nums{1, 3, 5, 7};
  std::cout << "nums contains " << nums.size() << " elements.\n";
  // using max_size()
  // The max_size() function returns the
  // maximum number of elements that can be stored in the vector.
  std::vector<char> s;
  std::cout << "Maximum size of a 'vector' is " << s.max_size() << "\n";
  // using capacity()
  // capacity() returns the number of elements that
  // the container has currently allocated space for.
  // capacity() does not change the size of the container.
  int sz = 200;
  std::vector<int> v1;
  auto cap = v1.capacity();
  std::cout << "initial capacity=" << cap << '\n';
  for (int n = 0; n < sz; ++n) {
    v1.push_back(n);
    if (cap != v1.capacity()) {
      cap = v1.capacity();
      std::cout << "new capacity=" << cap << '\n';
    }
  }
  std::cout << "final size=" << v1.size() << '\n';
  std::cout << "final capacity=" << v1.capacity() << '\n';
  // using shrink_to_fit()
  // shrink_to_fit() is a member function of vector class.
  // shrink_to_fit() is used to reduce the
  // capacity of the vector to the actual size of the vector.
  // shrink_to_fit() is useful when you know
  // that the vector will not be resized in the future.
  std::vector<int> v;
  std::cout << "Default-constructed capacity is " << v.capacity() << '\n';
  v.resize(100);
  std::cout << "Capacity of a 100-element vector is " << v.capacity() << '\n';
  v.resize(50);
  std::cout << "Capacity after resize(50) is " << v.capacity() << '\n';
  v.shrink_to_fit();
  std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
  v.clear();
  std::cout << "Capacity after clear() is " << v.capacity() << '\n';
  v.shrink_to_fit();
  std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
  for (int i = 1000; i < 1300; ++i) v.push_back(i);
  std::cout << "Capacity after adding 300 elements is " << v.capacity() << '\n';
  v.shrink_to_fit();
  std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
  // using resize()
  // resize() is a member function of vector class.
  // resize() is used to change the size of the vector.
  // resize() is useful when you know that the vector
  // will not be resized in the future.
  std::vector<int> c = {1, 2, 3};
  std::cout << "The vector holds: ";
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
  TzVectorCapacityCase01();
  TzVectorCapacityCase02();

  system("pause");
  return 0;
}
