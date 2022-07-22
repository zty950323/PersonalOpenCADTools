///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout;
using std::endl;
using std::pow;

void print_narcissistics() {
  for (int a = 1; a <= 9; ++a) {
    for (int b = 0; b <= 9; ++b) {
      for (int c = 0; c <= 9; ++c) {
        auto abc = a * 100 + b * 10 + c;
        auto arm = pow(a, 3) + pow(b, 3) + pow(c, 3);
        if (abc == arm) {
          cout << arm << endl;
        }
      }
    }
  }
}

int main() { print_narcissistics(); }
