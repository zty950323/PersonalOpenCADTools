
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

template <class Os, class Co>
Os& operator<<(Os& os, const Co& co) {
  os << "{";
  for (auto const& i : co) {
    os << ' ' << i;
  }
  return os << " } ";
}

// print the vector for show.
void printVector(const vector<int>& v) {
  for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void TzVectorSwapCase01() {
  vector<int> v1;
  for (int i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  printVector(v1);
  vector<int> v2;
  for (int i = 10; i > 0; i--) {
    v2.push_back(i);
  }
  printVector(v2);
  // swap v1 and v2.
  cout << "after swap:" << endl;
  v1.swap(v2);
  printVector(v1);
  printVector(v2);
}

void TzVectorSwapCase02() {
  std::vector<int> a1{1, 2, 3}, a2{4, 5};
  auto it1 = std::next(a1.begin());
  auto it2 = std::next(a2.begin());
  int& ref1 = a1.front();
  int& ref2 = a2.front();
  std::cout << a1 << a2 << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2
            << '\n';
  a1.swap(a2);
  std::cout << a1 << a2 << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2
            << '\n';

  // Note that after swap the iterators and references
  // stay associated with their
  // original elements, e.g. it1 that pointed to an
  // element in 'a1' with value 2
  // still points to the same element, though this
  // element was moved into 'a2'.
}

void TzVectorSwapCase03() {
  vector<int> v;
  for (int i = 0; i < 100000; i++) {
    v.push_back(i);
  }
  cout << "the capacity of the v is: " << v.capacity() << endl;
  cout << "the size of the v is :" << v.size() << endl;
  v.resize(3);
  cout << "the capacity of the v is:" << v.capacity() << endl;
  cout << "the size of the v is :" << v.size() << endl;
  // Shrink memory
  vector<int>(v).swap(v);  // Anonymous object
  cout << "the capacity of the v is: " << v.capacity() << endl;
  cout << "the size of the v is :" << v.size() << endl;
}

int main(int argc, char* argv[]) {
  TzVectorSwapCase01();
  TzVectorSwapCase02();
  TzVectorSwapCase03();
  system("pause");
  return 0;
}
