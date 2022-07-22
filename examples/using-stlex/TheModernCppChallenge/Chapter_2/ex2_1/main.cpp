///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  unsigned int limit = 0;
  cout << "Upper limit:";
  cin >> limit;
  unsigned long long sum = 0;
  for (unsigned int i = 3; i < limit; ++i)
  {
    if (0 == i % 3 || 0 == i % 5)
    {
      sum += i;
    }
  }
  cout << "sum= " << sum << endl;
}
