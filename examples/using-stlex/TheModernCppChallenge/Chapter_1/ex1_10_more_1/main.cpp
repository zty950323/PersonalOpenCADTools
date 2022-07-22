///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using std::bitset;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// This function generates all n bit Gray codes and prints the
// generated codes
void generateGrayarr(int n) {
  // base case
  if (n <= 0) return;

  // 'arr' will store all generated codes
  vector<string> arr;

  // start with one-bit pattern
  arr.push_back("0");
  arr.push_back("1");

  // Every iteration of this loop generates 2*i codes from previously
  // generated i codes.
  int i, j;
  for (i = 2; i < (1 << n); i = i << 1) {
    // Enter the prviously generated codes again in arr[] in reverse
    // order. Nor arr[] has double number of codes.
    for (j = i - 1; j >= 0; j--) arr.push_back(arr[j]);

    // append 0 to the first half
    for (j = 0; j < i; j++) arr[j] = "0" + arr[j];

    // append 1 to the second half
    for (j = i; j < 2 * i; j++) arr[j] = "1" + arr[j];
  }

  // print contents of arr[]
  for (i = 0; i < arr.size(); i++) cout << arr[i] << endl;
}

// This function generates all n
// bit Gray codes and prints the
// generated codes
vector<string> generateGray(int n) {
  // Base case
  if (n <= 0) return {"0"};

  if (n == 1) {
    return {"0", "1"};
  }

  // Recursive case
  vector<string> recAns = generateGray(n - 1);
  vector<string> mainAns;

  // Append 0 to the first half
  for (int i = 0; i < recAns.size(); i++) {
    string s = recAns[i];
    mainAns.push_back("0" + s);
  }

  // Append 1 to the second half
  for (int i = recAns.size() - 1; i >= 0; i--) {
    string s = recAns[i];
    mainAns.push_back("1" + s);
  }
  return mainAns;
}

// Function to generate the
// Gray code of N bits
void generateGrayarr_2(int n) {
  vector<string> arr;
  arr = generateGray(n);
  // print contents of arr
  for (int i = 0; i < arr.size(); i++) cout << arr[i] << endl;
}

void GrayCode(int n) {
  // power of 2
  for (int i = 0; i < (1 << n); i++) {
    // Generating the decimal
    // values of gray code then using
    // bitset to convert them to binary form
    int val = (i ^ (i >> 1));

    // Using bitset
    bitset<32> r(val);

    // Converting to string
    string s = r.to_string();
    cout << s.substr(32 - n) << " ";
  }
}

// Driver program to test above function
int main() {
  generateGrayarr(3);
  generateGrayarr_2(3);
  GrayCode(4);
  return 0;
}
