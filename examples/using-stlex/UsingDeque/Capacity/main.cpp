
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

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

// using capacity
void TzDequeCapacityCase01() {
  deque<int> d1;
  for (int i = 0; i < 10; i++) {
    d1.push_back(i);
  }
  printDeque(d1);
  // judge if the deque is full
  if (d1.empty()) {
    cout << "d1 is null!" << endl;
  } else {
    cout << "d1 is not null!" << endl;
    // record the size of deque
    cout << "the size of the d1 is:" << d1.size() << endl;
  }

  // infer the capacity of deque and the max_size of deque again.
  d1.resize(15, 1);
  printDeque(d1);

  d1.resize(5);
  printDeque(d1);
}

// other use ways.
void TzDequeCapacityCase02() {
  // using empty() and size().
  std::deque<int> numbers;
  std::cout << std::boolalpha;
  std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
  numbers.push_back(42);
  numbers.push_back(13317);
  std::cout << "After adding elements, numbers.empty(): " << numbers.empty()
            << '\n';

  // using size() and max_size().
  std::deque<int> nums{1, 3, 5, 7};
  std::cout << "nums contains " << nums.size() << " elements.\n";

  std::deque<char> s;
  std::cout << "Maximum size of a 'deque' is " << s.max_size() << "\n";

  // using resize().
  std::deque<int> c = {1, 2, 3};
  std::cout << "The deque holds: ";
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

void TzDequeCapacityCase03() {
  // using front() and back().
  std::deque<char> letters{'o', 'm', 'g', 'w', 't', 'f'};

  if (!letters.empty()) {
    std::cout << "The first character is '" << letters.front() << "'.\n";
  }

  std::deque<char> nletters{'a', 'b', 'c', 'd', 'e', 'f'};

  if (!nletters.empty()) {
    std::cout << "The last character is '" << nletters.back() << "'.\n";
  }
}

int main() {
  TzDequeCapacityCase01();
  TzDequeCapacityCase02();
  TzDequeCapacityCase03();

  system("pause");
  return 0;
}
