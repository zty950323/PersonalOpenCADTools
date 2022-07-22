///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout;
using std::endl;

void printCollatz(int n) {
  // We simply follow steps
  // while we do not reach 1
  while (n != 1) {
    cout << n << " ";
    // If n is odd
    if (n & 1) n = 3 * n + 1;
    // If even
    else
      n = n / 2;
  }

  // Print 1 at the end
  cout << n;
}

// Driver code
int main() {
  printCollatz(6);
  return 0;
}
