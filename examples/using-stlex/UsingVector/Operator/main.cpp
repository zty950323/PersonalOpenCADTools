
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

void printVector(const vector<int>& v) {
  for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

// operator=
void TzVectorOperatorCase01() {
  vector<int> v1;
  for (int i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  printVector(v1);
  vector<int> v2;
  v2 = v1;
  printVector(v2);
  vector<int> v3;
  v3.assign(v1.begin(), v1.end());
  printVector(v3);
  vector<int> v4;
  v4.assign(10, 100);
  printVector(v4);
}

// other operators.
void TzVectorOperatorCase02() {
  std::vector<int> alice{1, 2, 3};
  std::vector<int> bob{7, 8, 9, 10};
  std::vector<int> eve{1, 2, 3};
  std::cout << std::boolalpha;
  // Compare non equal containers
  std::cout << "alice == bob returns " << (alice == bob) << '\n';
  std::cout << "alice != bob returns " << (alice != bob) << '\n';
  std::cout << "alice <  bob returns " << (alice < bob) << '\n';
  std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
  std::cout << "alice >  bob returns " << (alice > bob) << '\n';
  std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
  std::cout << '\n';
  // Compare equal containers
  std::cout << "alice == eve returns " << (alice == eve) << '\n';
  std::cout << "alice != eve returns " << (alice != eve) << '\n';
  std::cout << "alice <  eve returns " << (alice < eve) << '\n';
  std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
  std::cout << "alice >  eve returns " << (alice > eve) << '\n';
  std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
}

int main() {
  TzVectorOperatorCase01();
  TzVectorOperatorCase02();
  system("pause");
  return 0;
}
