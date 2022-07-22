///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

class book {
  friend class read_book;
  double price;
  char *title;
  void display();
};

void book::display() { cout << title << ", price: " << price << endl; }

class read_book {
 public:
  read_book(book &b);
  void setBook();
  void read() const;

 private:
  book &m_b;
};

read_book::read_book(book &b) : m_b(b) {}

void read_book::setBook() {
  m_b.price = 29.9;
  m_b.title = const_cast<char *>("Alice in wonderland");
  m_b.display();
}

void read_book::read() const {
  cout << m_b.title << ", price: " << m_b.price << endl;
  // this can be read because I use the friend class.
}

int main() {
  book Alice;
  // Alice.price = 29.9;// compile error because this is private.
  // Alice.title = "Alice in wonderland";  // compile error because this is
  // private. Alice.display();        // compile error because this is private.
  read_book rb(Alice);
  rb.setBook();
  rb.read();
  return 0;
}