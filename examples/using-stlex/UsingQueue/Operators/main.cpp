
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <list>
#include <queue>

using std::cout;
using std::deque;
using std::endl;
using std::list;
using std::priority_queue;
using std::queue;
using std::vector;

void print_queue(queue<int>* q) {
  while (!q->empty()) {
    cout << q->front() << " ";
    q->pop();
  }
  cout << endl;
}

void test_queue() {
  cout << "============test_queue=============" << endl;
  clock_t timeStart = clock();
  queue<int, list<int>> c;
  for (int i = 0; i < 100000; i++) {
    c.push(i + 1);
  }
  cout << "stack.size()= " << c.size() << endl;
  cout << "stack.front()= " << c.front() << endl;
  c.pop();
  cout << "stack.size()= " << c.size() << endl;
  cout << "stack.front()= " << c.front() << endl;
  cout << "use list milli-seconds : " << (clock() - timeStart) << endl;

  timeStart = clock();
  queue<int, deque<int>> c1;
  for (int i = 0; i < 100000; i++) {
    c1.push(i + 1);
  }
  cout << "stack.size()= " << c1.size() << endl;
  cout << "stack.front()= " << c1.front() << endl;
  c1.pop();
  cout << "stack.size()= " << c1.size() << endl;
  cout << "stack.front()= " << c1.front() << endl;
  cout << "use deque milli-seconds : " << (clock() - timeStart) << endl;
}

void test_priority_queue() {
  cout << "============test_priority_queue=============" << endl;
  clock_t timeStart = clock();

  priority_queue<int, deque<int>> c1;
  for (int i = 0; i < 100000; i++) {
    c1.push(i + 1);
  }
  cout << "stack.size()= " << c1.size() << endl;
  cout << "stack.top()= " << c1.top() << endl;
  c1.pop();
  cout << "stack.size()= " << c1.size() << endl;
  cout << "stack.top()= " << c1.top() << endl;

  cout << "use deque milli-seconds : " << (clock() - timeStart) << endl;

  priority_queue<int, vector<int>> c2;
  for (int i = 0; i < 100000; i++) c2.push(i + 1);
  cout << "stack.size()= " << c2.size() << endl;
  cout << "stack.top()= " << c2.top() << endl;
  c2.pop();
  cout << "stack.size()= " << c2.size() << endl;
  cout << "stack.top()= " << c2.top() << endl;
  cout << "use stack milli-seconds : " << (clock() - timeStart) << endl;
}

void testNotEqual() {
  queue<int> q1, q2;
  for (int i = 0; i < 5; ++i) {
    q1.push(i + 1);
    q2.push(i + 1);
  }
  q1.pop();
  if (q1 != q2) cout << "q1 and q2 are not identical." << endl;
  q2.pop();
  if (!(q1 != q2)) cout << "q1 and q2 are identical." << endl;
}

void testMoreEqual() {
  queue<int> q1, q2;
  for (int i = 0; i < 5; ++i) {
    q1.push(i);
    q2.push(i);
  }
  if (q1 >= q2) cout << "q1 is greater than or equal to q2." << endl;
  q2.emplace(6);
  if (!(q1 >= q2)) cout << "q1 is not greater than or equal to q2." << endl;
}

void testLessEqual() {
  queue<int> q1, q2;
  for (int i = 0; i < 5; ++i) {
    q1.push(i);
    q2.push(i);
  }
  if (q1 <= q2) cout << "q1 is less than or equal to q2." << endl;
  q1.pop();
  if (!(q1 <= q2)) cout << "q1 is not less than or equal to q2." << endl;
}

void testMore() {
  queue<int> q1, q2;
  for (int i = 0; i < 5; ++i) {
    q1.push(i);
    q2.push(i);
  }
  q1.emplace(6);
  if (q1 > q2) cout << "q1 is greater than q2." << endl;
  q2.emplace(6);
  q2.emplace(7);
  if (!(q1 > q2)) cout << "q1 is not greater than q2." << endl;
}

void testLess() {
  queue<int> q1, q2;
  for (int i = 0; i < 5; ++i) q1.push(i);
  for (int i = 0; i < 15; ++i) q2.push(i);
  if (q1 < q2) cout << "q1 is less than q2." << endl;
  q2.swap(q1);
  if (!(q1 < q2)) cout << "q1 is not less than q2." << endl;
}

void testEqual() {
  queue<int> q1, q2;
  for (int i = 0; i < 5; ++i) {
    q1.push(i + 1);
    q2.push(i + 1);
  }
  if (q1 == q2) cout << "q1 and q2 are identical." << endl;
  q1.push(6);
  if (!(q1 == q2)) cout << "q1 and q2 are not identical." << endl;
}

int main(int argc, char* argv[]) {
  test_queue();
  test_priority_queue();
  testNotEqual();
  testEqual();
  testMore();
  testMoreEqual();
  testLess();
  testLessEqual();
  system("pause");
  return 0;
}
