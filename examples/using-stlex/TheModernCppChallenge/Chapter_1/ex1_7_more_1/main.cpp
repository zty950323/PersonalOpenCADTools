///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

// A simple C++ program to count
// amicable pairs in an array.
#include <iostream>

using std::cout;
using std::endl;
using std::sqrt;

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

// This function prints pair
// of amicable pairs present
// in the input array
int countPairs(int arr[], int n) {
  int count = 0;

  // Iterate through each
  // pair, and find if it
  // an amicable pair
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (isAmicable(arr[i], arr[j])) count++;

  return count;
}

// Driver code
int main() {
  int arr1[] = {220, 284, 1184, 1210, 2, 5};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  cout << countPairs(arr1, n1) << endl;

  int arr2[] = {2620, 2924, 5020, 5564, 6232, 6368};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << countPairs(arr2, n2);
  return 0;
}
