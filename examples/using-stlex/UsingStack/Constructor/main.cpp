
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

void TzConstructorCase01() {
  std::stack<int> s;
  s.push(2);
  s.push(6);
  s.push(51);
  printStack<int>(&s);
  std::stack<double> t;
  std::default_random_engine e;
  std::uniform_real_distribution<double> u(-100.0, 100.0);
  for (decltype(t.size()) i = 0; i < 30; ++i) {
    t.push(u(e));
  }
  printStack<double>(&t);
}

void TzConstructorCase02() {
  std::stack<int> c1;
  c1.push(5);
  std::cout << c1.size() << '\n';
  std::stack<int> c2(c1);
  std::cout << c2.size() << '\n';
  std::deque<int> deq{3, 1, 4, 1, 5};
  std::stack<int> c3(deq);
  std::cout << c3.size() << '\n';
}

int main(int argc, char* argv[]) {
  TzConstructorCase01();
  TzConstructorCase02();
  system("pause");
  return 0;
}
