
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// print the vector for show.
void printVector(const vector<int>& v) {
  for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void TzVectorConstructorCase01() {
  vector<int> v1;  // constructor without any param.
  for (int i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  printVector(v1);
  // constructor with param with a certain vector's start and end.
  vector<int> v2(v1.begin(), v1.end());
  printVector(v2);
  // constructor with param with range.
  vector<int> v3(10, 100);
  printVector(v3);
  // constructor with param with a certain vector.
  vector<int> v4(v3);
  printVector(v4);
}

int main(int argc, char* argv[]) {
  TzVectorConstructorCase01();
  system("pause");
  return 0;
}
