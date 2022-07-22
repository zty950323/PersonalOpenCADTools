
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iomanip>
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

void print_container(const std::vector<int>& c) {
  for (auto& i : c) {
    std::cout << i << " ";
  }
  std::cout << '\n';
}

void TzVectorInsertAndDeleteCase01() {
  vector<int> v1;
  // insert at the end.
  v1.push_back(10);
  v1.push_back(20);
  v1.push_back(30);
  v1.push_back(40);
  v1.push_back(50);
  printVector(v1);
  // delete at the end.
  v1.pop_back();
  printVector(v1);
  // insert at the begin.
  v1.insert(v1.begin(), 100);
  printVector(v1);
  v1.insert(v1.begin(), 2, 1000);
  printVector(v1);
  // delete at the begin.
  v1.erase(v1.begin());
  printVector(v1);
  // clear the vector.
  v1.erase(v1.begin(), v1.end());
  v1.clear();
  printVector(v1);
}

void TzVectorInsertAndDeleteCase02() {
  std::vector<int> vec(3, 100);
  printVector(vec);
  auto it = vec.begin();
  it = vec.insert(it, 200);
  printVector(vec);
  vec.insert(it, 2, 300);
  printVector(vec);
  // "it" no longer valid, get a new one:
  it = vec.begin();
  std::vector<int> vec2(2, 400);
  vec.insert(it + 2, vec2.begin(), vec2.end());
  printVector(vec);
  int arr[] = {501, 502, 503};
  vec.insert(vec.begin(), arr, arr + 3);
  printVector(vec);
}

void TzVectorInsertAndDeleteCase03() {
  std::vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  print_container(c);
  c.erase(c.begin());
  print_container(c);
  c.erase(c.begin() + 2, c.begin() + 5);
  print_container(c);
  // Erase all even numbers (C++11 and later)
  for (auto it = c.begin(); it != c.end();) {
    if (*it % 2 == 0) {
      it = c.erase(it);
    } else {
      ++it;
    }
  }
  print_container(c);
}

void TzVectorInsertAndDeleteCase04() {
  std::vector<std::string> letters;
  letters.push_back("abc");
  std::string s = "def";
  letters.push_back(std::move(s));
  std::cout << "vector holds: ";
  for (auto&& i : letters) std::cout << std::quoted(i) << ' ';
  std::cout << "\nMoved-from string holds " << std::quoted(s) << '\n';
}

void TzVectorInsertAndDeleteCase05() {
  std::vector<int> container{1, 2, 3};
  auto print = [](const int& n) { std::cout << " " << n; };
  std::cout << "Before clear:";
  std::for_each(container.begin(), container.end(), print);
  std::cout << "\nSize=" << container.size() << '\n';
  std::cout << "Clear\n";
  container.clear();
  std::cout << "After clear:";
  std::for_each(container.begin(), container.end(), print);
  std::cout << "\nSize=" << container.size() << '\n';
}

void TzVectorInsertAndDeleteCase06() {
  std::vector<int> numbers;
  print_container(numbers);
  numbers.push_back(5);
  numbers.push_back(3);
  numbers.push_back(4);
  print_container(numbers);
  numbers.pop_back();
  print_container(numbers);
}

int main(int argc, char* argv[]) {
  TzVectorInsertAndDeleteCase01();
  TzVectorInsertAndDeleteCase02();
  TzVectorInsertAndDeleteCase03();
  TzVectorInsertAndDeleteCase04();
  TzVectorInsertAndDeleteCase05();
  TzVectorInsertAndDeleteCase06();
  system("pause");
  return 0;
}
