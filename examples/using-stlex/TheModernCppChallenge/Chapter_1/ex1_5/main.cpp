///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool is_prime(int const num) {
  if (num <= 3) {
    return num > 1;
  } else if (num % 2 == 0 || num % 3 == 0) {
    return false;
  } else {
    for (int i = 5; i * i <= num; i += 6) {
      if (num % i == 0 || num % (i + 2) == 0) {
        return false;
      }
    }
    return true;
  }
}

void printSexyPrimePairs(int const limit) {
  for (int n = 2; n <= limit; n++) {
    if (is_prime(n) && is_prime(n + 6)) {
      cout << n << "," << n + 6 << endl;
    }
  }
}

void printSexyPrimeThreePairs(int const limit) {
  for (int n = 2; n <= limit; n++) {
    if (is_prime(n) && is_prime(n + 6) && is_prime(n + 12)) {
      cout << n << "," << n + 6 << "," << n + 12 << endl;
    }
  }
}

void printSexyPrimeFourPairs(int const limit) {
  for (int n = 2; n <= limit; n++) {
    if (is_prime(n) && is_prime(n + 6) && is_prime(n + 12) &&
        is_prime(n + 18)) {
      cout << n << "," << n + 6 << "," << n + 12 << "," << n + 18 << endl;
    }
  }
}

void printSexyPrimeFivePairs(int const limit) {
  for (int n = 2; n <= limit; n++) {
    if (is_prime(n) && is_prime(n + 6) && is_prime(n + 12) &&
        is_prime(n + 18) && is_prime(n + 24)) {
      cout << n << "," << n + 6 << "," << n + 12 << "," << n + 18 << ","
           << n + 24 << endl;
    }
  }
}

void printSexyPrime(int const limit, int const pairNums) {
  for (int n = 2; n <= limit; n++) {
    int j = 0;
    for (; j < pairNums; ++j) {
      if (is_prime(n + j * 6)) {
        continue;
      }

      break;
    }
    if (j == pairNums) {
      for (int k = 0; k < pairNums; k++) {
        cout << n + k * 6 << ",";
      }
      cout << endl;
    }
  }
}

int main() {
  int limit = 0;
  cout << "Upper limit:";
  cin >> limit;
  cout << "print two pair:" << endl;
  printSexyPrimePairs(limit);
  printSexyPrime(limit, 2);
  cout << "print three pair:" << endl;
  printSexyPrimeThreePairs(limit);
  printSexyPrime(limit, 3);
  cout << "print four pair:" << endl;
  printSexyPrimeFourPairs(limit);
  printSexyPrime(limit, 4);
  cout << "print five pair:" << endl;
  printSexyPrimeFivePairs(limit);
  printSexyPrime(limit, 5);
}
