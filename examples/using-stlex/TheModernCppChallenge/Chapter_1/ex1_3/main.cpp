///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::gcd;

namespace {
constexpr unsigned int Random_Max = 1000000;
constexpr unsigned int Random_Times = 100;
}  // namespace

int lcm(int const a, int const b) {
  int h = gcd(a, b);
  return h ? (a * (b / h)) : 0;
}

template <class InputIt>
int lcmr(InputIt first, InputIt last) {
  return std::accumulate(first, last, 1, lcm);
}

int main() {
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_int_distribution<> dis(1, Random_Max);
  std::vector<decltype(dis(gen))> testData;
  for (unsigned int i = 0; i < Random_Times; ++i) {
    testData.push_back(dis(gen));
    auto it = testData.begin();
    cout << "lcmr result:"
         << lcmr<decltype(it)>(testData.begin(), testData.end()) << endl;
  }
  for (unsigned int i = 0; i < Random_Times; ++i) {
    auto num_a = dis(gen);
    auto num_b = dis(gen);
    cout << "lcm result:" << lcm(num_a, num_b) << endl;
    // in c++17 we can use this way:
    cout << "C++17 using numeric gcd:" << std::lcm(num_a, num_b) << endl;
  }
}
