///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;

// Function to convert decimal to Roman Numerals
int printRoman(int number) {
  int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
  string sym[] = {"I",  "IV", "V",  "IX", "X",  "XL", "L",
                  "XC", "C",  "CD", "D",  "CM", "M"};
  int i = 12;
  while (number > 0) {
    int div = number / num[i];
    number = number % num[i];
    while (div--) {
      cout << sym[i];
    }
    i--;
  }
  return -1;
}

// Function to calculate roman equivalent
string intToRoman(int num) {
  // storing roman values of digits from 0-9
  // when placed at different places
  string m[] = {"", "M", "MM", "MMM"};
  string c[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  string x[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  string i[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

  // Converting to roman
  string thousands = m[num / 1000];
  string hundreds = c[(num % 1000) / 100];
  string tens = x[(num % 100) / 10];
  string ones = i[num % 10];

  string ans = thousands + hundreds + tens + ones;

  return ans;
}

// Driver program
int main() {
  printRoman(3549);
  cout << intToRoman(3548);
  return 0;
}
