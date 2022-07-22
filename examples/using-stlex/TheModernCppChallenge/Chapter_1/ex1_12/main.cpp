///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::vector;

pair<uint64_t, long> longest_collatz(uint64_t const limit) {
  long length = 0;
  uint64_t number = 0;
  vector<int> cache(limit + 1, 0);
  for (uint64_t i = 2; i <= limit; ++i) {
    auto n = i;
    long steps = 0;
    while (n != 1 && n >= i) {
      if ((n % 2) == 0)
        n = n / 2;
      else
        n = n * 3 + 1;
      steps++;
    }
    cache[i] = steps + cache[n];

    if (cache[i] > length) {
      length = cache[i];
      number = i;
    }
  }

  return make_pair(number, length);
}

int main() {
  uint64_t limit = 0;
  cout << "Upper Limit";
  cin >> limit;
  if (limit >= 1000000) {
    cout << "Too Large Number" << endl;
    return -1;
  }
  auto result = longest_collatz(limit);
  cout << "Number :" << result.first << "\tLength :" << result.second << endl;
  return 0;
}