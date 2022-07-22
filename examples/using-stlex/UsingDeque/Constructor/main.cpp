
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <deque>
#include <iostream>
#include <string>

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
std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {
  s.put('[');
  char comma[3] = {'\0', ' ', '\0'};
  for (const auto& e : v) {
    s << comma << e;
    comma[0] = ',';
  }
  return s << ']';
}

// the constructor of deque
void TzDequeConstructorCase01() {
  deque<int> d1;  // construct an empty deque
  for (int i = 0; i < 10; i++) {
    d1.push_back(i);
  }

  printDeque(d1);
  deque<int> d2(d1.begin(), d1.end());
  printDeque(d2);

  deque<int> d3(10, 100);
  printDeque(d3);

  deque<int> d4 = d3;
  printDeque(d4);
}

void TzDequeConstructorCase02() {
  // c++11 initializer list syntax:
  std::deque<std::string> words1{"the", "frogurt", "is", "also", "cursed"};
  std::cout << "words1: " << words1 << '\n';

  // words2 == words1
  std::deque<std::string> words2(words1.begin(), words1.end());
  std::cout << "words2: " << words2 << '\n';

  // words3 == words1
  std::deque<std::string> words3(words1);
  std::cout << "words3: " << words3 << '\n';

  // words4 is {"Mo", "Mo", "Mo", "Mo", "Mo"}
  std::deque<std::string> words4(5, "Mo");
  std::cout << "words4: " << words4 << '\n';
}

int main(int argc, char* argv[]) {
  TzDequeConstructorCase01();
  TzDequeConstructorCase02();

  system("pause");
  return 0;
}
