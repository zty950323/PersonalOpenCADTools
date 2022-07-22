///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

struct book {
  double price;
  char* title;
  void display();
};

void book::display() { cout << title << ", price: " << price << endl; }

int main() {
  book Alice;
  Alice.price = 29.9;                                      // It's OK
  Alice.title = const_cast<char*>("Alice in wonderland");  // It's OK
  Alice.display();                                         // It's OK
  return 0;
}