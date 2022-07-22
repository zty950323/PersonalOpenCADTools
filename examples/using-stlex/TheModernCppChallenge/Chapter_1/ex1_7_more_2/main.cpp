///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

// Efficient C++ program to count
// Amicable pairs in an array.
#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::sqrt;
using std::unordered_set;

// Calculate the sum
// of proper divisors
int sumOfDiv(int x) {
  // 1 is a proper divisor
  int sum = 1;
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      sum += i;

      // To handle perfect squares
      if (x / i != i) sum += x / i;
    }
  }
  return sum;
}

// Check if pair is amicable
bool isAmicable(int a, int b) { return (sumOfDiv(a) == b && sumOfDiv(b) == a); }

// This function prints count
// of amicable pairs present
// in the input array
int countPairs(int arr[], int n) {
  // Map to store the numbers
  unordered_set<int> s;
  int count = 0;
  for (int i = 0; i < n; i++) s.insert(arr[i]);

  // Iterate through each number,
  // and find the sum of proper
  // divisors and check if it's
  // also present in the array
  for (int i = 0; i < n; i++) {
    if (s.find(sumOfDiv(arr[i])) != s.end()) {
      // It's sum of proper divisors
      int sum = sumOfDiv(arr[i]);
      if (isAmicable(arr[i], sum)) count++;
    }
  }

  // As the pairs are counted
  // twice, thus divide by 2
  return count / 2;
}

// Driver code
int main() {
  int arr1[] = {220, 284, 1184, 1210, 2, 5};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  cout << countPairs(arr1, n1) << endl;

  int arr2[] = {2620, 2924, 5020, 5564, 6232, 6368};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << countPairs(arr2, n2) << endl;
  return 0;
}
