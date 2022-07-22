
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using std::begin;
using std::cin;
using std::copy;
using std::cout;
using std::end;
using std::endl;
using std::ostream_iterator;
using std::sqrt;
using std::vector;

vector<uint64_t> prime_factors(uint64_t n) {
  vector<uint64_t> factors;
  while (n % 2 == 0) {
    factors.push_back(2);
    n = n / 2;
  }
  for (uint64_t i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      factors.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) factors.push_back(n);
  return factors;
}

void primeFactors(int n) {
  int c = 2;
  while (n > 1) {
    if (n % c == 0) {
      cout << c << " ";
      n /= c;
    } else
      c++;
  }
}

int main() {
  uint64_t number = 0;
  cout << "number:";
  cin >> number;
  auto factors = prime_factors(number);
  copy(begin(factors), end(factors), ostream_iterator<uint64_t>(cout, " "));
  primeFactors(number);
}
