
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <deque>     // std::deque
#include <iostream>  // std::cout
#include <list>      // std::list
#include <queue>     // std::queue

using std::cout;
using std::endl;
using std::list;
using std::queue;

void print(std::queue<int>* q) {
  while (!q->empty()) {
    std::cout << q->front() << " ";
    q->pop();
  }
  std::cout << std::endl;
}

void test01() {
  std::deque<int> mydeck(3, 100);  // deque with 3 elements
  std::list<int> mylist(2, 200);   // list with 2 elements
  std::queue<int> first;           // empty queue
  std::queue<int> second(mydeck);  // queue initialized to copy of deque
  std::queue<int, std::list<int> > third;
  // empty queue with list as underlying container
  std::queue<int, std::list<int> > fourth(mylist);
  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
}

void test02() {
  auto it1 = {1, 2, 3, 4, 5};
  auto it2 = {10, 20};
  queue<int> q1(it1);
  queue<int> q2(it2);
  q2 = q1;
  cout << "Contents of q1" << endl;
  while (!q1.empty()) {
    cout << q1.front() << endl;
    q1.pop();
  }
  cout << endl;
  cout << "Contents of q2" << endl;
  while (!q2.empty()) {
    cout << q2.front() << endl;
    q2.pop();
  }
}

int main() {
  // queue is a container adaptor, which provides a FIFO (first-in, first-out)
  std::queue<int> c1;
  c1.push(5);
  std::cout << c1.size() << '\n';
  print(&c1);
  std::queue<int> c2(c1);
  std::cout << c2.size() << '\n';
  print(&c2);
  std::deque<int> deq{3, 1, 4, 1, 5};
  std::queue<int> c3(deq);
  std::cout << c3.size() << '\n';
  print(&c3);
  std::queue<int> c4;
  c4 = c3;
  std::cout << c4.size() << '\n';
  print(&c4);

  test01();
  test02();
  return 0;
}
