
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

void usuallyTest01() {
  // Create a stack container. Stack containers must comply
  // with the requirements of first in first out (FIFO).
  stack<int> s;
  // Adding elements to the stack is called pushing on the stack.
  s.push(10);
  s.push(20);
  s.push(30);
  while (!s.empty()) {
    // Output stack top element and remove it from the stack.
    cout << "the top element of the stack is:" << s.top() << endl;
    // Pop up stack top element.
    s.pop();
  }
  cout << "the size of this stack is:" << s.size() << endl;
}

int main(int argc, char* argv[]) {
  usuallyTest01();
  system("pause");
  return 0;
}
