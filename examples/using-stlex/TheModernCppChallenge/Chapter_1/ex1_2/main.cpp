///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <numeric>
#include <random>

using std::cin;
using std::cout;
using std::endl;

namespace {
constexpr unsigned int Random_Max = 1000000;
constexpr unsigned int Random_Times = 100;
}  // namespace

unsigned int gcd_r(unsigned int const a, unsigned int const b) {
  return 0 == b ? a : gcd_r(b, a % b);
}

unsigned int gcd(unsigned int a, unsigned int b) {
  while (b != 0) {
    unsigned int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_int_distribution<> dis(1, Random_Max);
  for (unsigned int i = 0; i < Random_Times; ++i) {
    auto num_a = dis(gen);
    auto num_b = dis(gen);
    cout << "gcd_r:" << gcd_r(num_a, num_b) << endl;
    cout << "gcd:" << gcd(num_a, num_b) << endl;
    // in c++17 we can use this way:
    cout << "C++17 using numeric gcd:" << std::gcd(num_a, num_b) << endl;
  }
}