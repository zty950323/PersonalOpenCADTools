
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

// print the vector for show.
void printVector(const vector<int>& v) {
  for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void TzVectorStoreDataCase01() {
  vector<int> v1;
  for (int i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  // using [] to access the element.
  for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << " ";
  }
  cout << endl;
  // using at() to access the element.
  for (int i = 0; i < v1.size(); i++) {
    cout << v1.at(i) << " ";
  }
  cout << endl;
  cout << "the first element of v1 is： " << v1.front() << endl;
  cout << "the last element of v1 is： " << v1.back() << endl;
}

void TzVectorStoreDataCase02() {
  std::vector<int> numbers{2, 4, 6, 8};
  // using [] to access the element.
  std::cout << "Second element: " << numbers[1] << '\n';
  numbers[0] = 5;
  std::cout << "All numbers:";
  for (auto i : numbers) {
    std::cout << ' ' << i;
  }
  std::cout << '\n';
}

// using at() to access the element.
void TzVectorStoreDataCase03() {
  std::vector<int> data = {1, 2, 4, 5, 5, 6};
  // Set element 1
  data.at(1) = 88;
  // Read element 2
  std::cout << "Element at index 2 has value " << data.at(2) << '\n';
  std::cout << "data size = " << data.size() << '\n';
  try {
    // Set element 6
    data.at(6) = 666;
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
  TzVectorStoreDataCase01();
  TzVectorStoreDataCase02();
  TzVectorStoreDataCase03();
  system("pause");
  return 0;
}
