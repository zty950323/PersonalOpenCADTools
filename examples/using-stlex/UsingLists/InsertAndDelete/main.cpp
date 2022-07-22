
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iomanip>
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

void print_container(const std::list<int>& c) {
  for (auto& i : c) {
    std::cout << i << " ";
  }
  std::cout << '\n';
}

void TzListInsertAndDeleteCase01() {
  list<int> v1;

  // insert at the end.
  v1.push_back(10);
  v1.push_back(20);
  v1.push_back(30);
  v1.push_back(40);
  v1.push_back(50);
  printList(v1);

  // delete at the end.
  v1.pop_back();
  printList(v1);
  // insert at the begin.
  v1.insert(v1.begin(), 100);
  printList(v1);

  v1.insert(v1.begin(), 2, 1000);
  printList(v1);

  // delete at the begin.
  v1.erase(v1.begin());
  printList(v1);

  // clear the list.
  v1.erase(v1.begin(), v1.end());
  v1.clear();
  printList(v1);
}

void TzListInsertAndDeleteCase02() {
  std::list<int> vec(3, 100);
  printList(vec);

  auto it = vec.begin();
  it = vec.insert(it, 200);
  printList(vec);

  vec.insert(it, 2, 300);
  printList(vec);

  // "it" no longer valid, get a new one:
  it = vec.begin();
  for (size_t i = 0; i < 2; ++i) {
    it++;
  }

  std::list<int> vec2(2, 400);
  vec.insert(it, vec2.begin(), vec2.end());
  printList(vec);

  int arr[] = {501, 502, 503};
  vec.insert(vec.begin(), arr, arr + 3);
  printList(vec);
}

void TzListInsertAndDeleteCase03() {
  std::list<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  print_container(c);

  c.erase(c.begin());
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

void TzListInsertAndDeleteCase04() {
  std::list<std::string> letters;
  letters.push_back("abc");
  std::string s = "def";
  letters.push_back(std::move(s));
  std::cout << "list holds: ";
  for (auto&& i : letters) std::cout << std::quoted(i) << ' ';
  std::cout << "\n Moved-from string holds " << std::quoted(s) << '\n';
}

void TzListInsertAndDeleteCase05() {
  std::list<int> container{1, 2, 3};
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

void TzListInsertAndDeleteCase06() {
  std::list<int> numbers;

  print_container(numbers);

  numbers.push_back(5);
  numbers.push_back(3);
  numbers.push_back(4);

  print_container(numbers);

  numbers.pop_back();

  print_container(numbers);
}

int main(int argc, char* argv[]) {
  TzListInsertAndDeleteCase01();
  TzListInsertAndDeleteCase02();
  TzListInsertAndDeleteCase03();
  TzListInsertAndDeleteCase04();
  TzListInsertAndDeleteCase05();
  TzListInsertAndDeleteCase06();

  system("pause");
  return 0;
}
