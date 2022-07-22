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
using std::pair;
using std::vector;

int sum_proper_divisors(int const number) {
  int result = 1;
  for (int i = 2; i <= std::sqrt(number); i++) {
    if (number % i == 0) {
      result += (i == (number / i)) ? i : (i + number / i);
    }
  }
  return result;
}

void count_amicables(int const limit) {
  for (int i = 4; i < limit; ++i) {
    auto sum1 = sum_proper_divisors(i);
    if (sum1 < limit) {
      auto sum2 = sum_proper_divisors(sum1);
      if (sum2 == i && i != sum1) {
        cout << i << ',' << sum1 << endl;
      }
    }
  }
}

void count_amicables_single(int const limit) {
  vector<pair<int, int>> amicables;
  for (int i = 4; i < limit; ++i) {
    auto sum1 = sum_proper_divisors(i);
    if (sum1 < limit) {
      auto sum2 = sum_proper_divisors(sum1);
      if (sum2 == i && i != sum1) {
        auto aSize = amicables.size();
        bool needToPrint = true;
        for (decltype(aSize) k = 0; k < aSize; ++k) {
          const pair<int, int>& curAmi = amicables.at(k);
          int curAmiFirst = curAmi.first;
          int curAmiSecond = curAmi.second;
          if (sum1 == curAmiFirst && sum2 == curAmiSecond ||
              sum2 == curAmiFirst && sum1 == curAmiSecond) {
            needToPrint = false;
          }
        }
        if (needToPrint) {
          pair<int, int> amicable(sum1, sum2);
          cout << i << ',' << sum1 << endl;
          amicables.push_back(amicable);
        }
      }
    }
  }
}

int main() {
  int limit = 0;
  cout << "Upper limit:";
  cin >> limit;
  cout << "Not single outputs:" << endl;
  count_amicables(limit);
  cout << "single outputs:" << endl;
  count_amicables_single(limit);
  return 0;
}