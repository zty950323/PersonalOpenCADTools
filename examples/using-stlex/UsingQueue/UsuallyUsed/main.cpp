
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <string>

using std::cout;
using std::endl;
using std::queue;
using std::string;

class Person {
 public:
  Person(string name, int age) : m_name(name), m_age(age) {}

  string m_name;
  int m_age;
};

void UsuallyTest01() {
  // to create a queue.
  queue<Person> q;
  // to add an element to the queue.
  Person p1("Tang Shen", 30);
  Person p2("Song Wukong", 1000);
  Person p3("Zhu Bajie", 900);
  Person p4("Sha Shen", 800);
  // to add an element to the queue.
  q.push(p1);
  q.push(p2);
  q.push(p3);
  q.push(p4);
  // to get the front element of the queue.
  while (!q.empty()) {
    // to get the front element of the queue.
    cout << "The front element - Name: " << q.front().m_name
         << " Age: " << q.front().m_age << endl;
    cout << "The back element - Name: " << q.back().m_name
         << " Age: " << q.back().m_age << endl;
    cout << endl;
    // to remove the front element of the queue.
    q.pop();
  }
  cout << "The size of the queue is: " << q.size() << endl;
}

int main() {
  UsuallyTest01();
  system("pause");
  return 0;
}
