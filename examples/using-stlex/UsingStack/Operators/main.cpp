
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <random>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

template <typename T>
void printStack(std::stack<T>* s) {
  std::cout << s->size() << " elements on stack\n";
  std::cout << "Top element: " << s->top()  // Leaves element on stack
            << "\n";
  std::cout << s->size() << " elements on stack\n";
  s->pop();
  std::cout << s->size() << " elements on stack\n";
  std::cout << "Top element: " << s->top() << "\n";
  for (decltype(s->size()) i = 0; i < s->size(); ++i) {
    s->pop();
    std::cout << s->top();
  }
}

void TzOperatorCase01() {
  std::stack<double> s;
  std::default_random_engine e;
  std::uniform_real_distribution<double> u(-200.0, 200.0);
  for (decltype(s.size()) i = 0; i < 50; ++i) {
    s.push(u(e));
  }
  printStack<double>(&s);
  std::stack<int> t;
  std::uniform_int_distribution<int> l(-10, 10);
  for (decltype(t.size()) i = 0; i < 50; ++i) {
    t.push(l(e));
  }

  for (int i = -10; i < 10; ++i) {
    if (i == t.top()) {
      std::cout << t.top() << std::endl;
      t.pop();
    }
    if (i > t.top() || i < t.top()) {
      std::cout << i << std::endl;
    }
  }
  std::stack<int> tt(t);
  if (tt == t) {
    printStack<int>(&t);
  }
}

int main(int argc, char* argv[]) {
  TzOperatorCase01();
  system("pause");
  return 0;
}
