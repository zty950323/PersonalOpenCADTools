
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <list>
#include <queue>

using std::cout;
using std::endl;
using std::list;
using std::queue;

void print_queue(queue<int>* q) {
  while (!q->empty()) {
    cout << q->front() << " ";
    q->pop();
  }
  cout << endl;
}

void testSwap() {
  queue<int> q1, q2;
  for (int i = 0; i < 5; ++i) q1.push(i + 1);
  for (int i = 0; i < 2; ++i) q2.push(i + 150);
  q1.swap(q2);
  cout << "Content of q1 and q2 after swap operation" << endl;
  while (!q1.empty()) {
    cout << q1.front() << endl;
    q1.pop();
  }
  cout << endl;
  while (!q2.empty()) {
    cout << q2.front() << endl;
    q2.pop();
  }
}

int main(int argc, char* argv[]) {
  testSwap();
  system("pause");
  return 0;
}
