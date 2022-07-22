///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <bitset>
#include <iostream>
#include <string>

using std::bitset;
using std::cout;
using std::endl;
using std::string;

uint32_t gray_encode(uint32_t const num) { return num ^ (num >> 1); }

uint32_t gray_decode(uint32_t gray) {
  for (uint32_t bit = 1U << 31; bit > 1; bit >>= 1) {
    if (gray & bit) gray ^= bit >> 1;
  }
  return gray;
}

string to_binary(uint32_t value, int const digits) {
  return bitset<32>(value).to_string().substr(32 - digits, digits);
}

int main() {
  cout << "Number\tBinary\tGray\tDecoded\n";
  cout << "------\t------\t----\t-------\n";

  for (uint32_t i = 0; i < 32; ++i) {
    auto encg = gray_encode(i);
    auto decg = gray_decode(encg);
    cout << i << '\t' << to_binary(i, 5) << '\t' << to_binary(encg, 5) << '\t'
         << decg << endl;
  }
}
