
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <deque>
#include <iomanip>
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

template <typename T>
void print(T const& xs) {
  std::cout << "[ ";
  for (auto const& x : xs) {
    std::cout << x << ' ';
  }
  std::cout << "]\n";
}

void print_container(const std::deque<int>& c) {
  for (auto& i : c) {
    std::cout << i << " ";
  }
  std::cout << '\n';
}

void TzDequeInsertAndDeleteCase01() {
  deque<int> d;
  // insert at the end.
  d.push_back(10);
  d.push_back(20);
  // insert at the beginning.
  d.push_front(100);
  d.push_front(200);

  printDeque(d);

  // delete at the end.
  d.pop_back();
  // delete at the beginning.
  d.pop_front();
  printDeque(d);
}

void TzDequeInsertAndDeleteCase02() {
  // insert elements for the first time.
  deque<int> d;
  d.push_back(10);
  d.push_back(20);
  d.push_front(100);
  d.push_front(200);
  printDeque(d);

  // insert element at the beginning.
  d.insert(d.begin(), 1000);
  printDeque(d);

  d.insert(d.begin(), 2, 10000);
  printDeque(d);

  deque<int> d2;
  d2.push_back(1);
  d2.push_back(2);
  d2.push_back(3);

  // insert other elements by copy.
  d.insert(d.begin(), d2.begin(), d2.end());
  printDeque(d);
}

void TzDequeInsertAndDeleteCase03() {
  deque<int> d;
  d.push_back(10);
  d.push_back(20);
  d.push_front(100);
  d.push_front(200);
  printDeque(d);

  // delete element at the beginning.
  d.erase(d.begin());
  printDeque(d);

  d.erase(d.begin(), d.end());
  d.clear();
  printDeque(d);
}

void TzDequeInsertAndDeleteCase04() {
  // using push_back and pop_back.
  std::deque<std::string> letters;

  letters.push_back("abc");
  std::string s = "def";
  letters.push_back(std::move(s));

  std::cout << "deque holds: ";
  for (auto&& i : letters) std::cout << std::quoted(i) << ' ';
  std::cout << "\n Moved-from string holds " << std::quoted(s) << '\n';
}

void TzDequeInsertAndDeleteCase05() {
  // using push_back and pop_back.
  std::deque<int> numbers;

  print(numbers);
  numbers.push_back(5);
  numbers.push_back(3);
  numbers.push_back(4);

  print(numbers);
  numbers.pop_back();
  print(numbers);
}

void TzDequeInsertAndDeleteCase06() {
  // using clear.
  std::deque<int> container{1, 2, 3};

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

void TzDequeInsertAndDeleteCase07() {
  // using erase.
  std::deque<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
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

int main(int argc, char* argv[]) {
  TzDequeInsertAndDeleteCase01();
  TzDequeInsertAndDeleteCase02();
  TzDequeInsertAndDeleteCase03();
  TzDequeInsertAndDeleteCase04();
  TzDequeInsertAndDeleteCase05();
  TzDequeInsertAndDeleteCase06();
  TzDequeInsertAndDeleteCase07();
  system("pause");
  return 0;
}
