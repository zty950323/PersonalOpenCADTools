///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <string_view>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::string_view;

bool validate_isbn_10(const string_view& isbn) {
  auto valid = false;
  if (10 == isbn.size() &&
      10 == std::count_if(begin(isbn), end(isbn), isdigit)) {
    auto w = 10;
    auto sum = std::accumulate(begin(isbn), end(isbn), 0,
                               [&w](const int& total, const char& c) {
                                 return total + w-- * (c - '0');
                               });
    valid = !(sum % 11);
  }
  return valid;
}

// this is not a valid function, get a wrong result.
bool validate_isbn_13(const string_view& isbn) {
  auto valid = false;
  if (13 == isbn.size() &&
      13 == std::count_if(begin(isbn), end(isbn), isdigit)) {
    int sum = 0;
    int p;
    int num;
    for (int ix = 0; ix < isbn.length(); ix++) {
      p = isbn.at(ix) - '0';

      if ((ix % 2) == 0) {
        num = p;
      } else {
        num = 3 * p;
      }
      sum += num;
    }  // end for()
    valid = !(sum % 10);
  }
  return valid;
}

bool validate_isbn_with_hyphens(const string& isbn) {
  auto valid = false;
  auto str = isbn;
  str.erase(std::remove(str.begin(), str.end(), '-'), str.end());
  if (10 == str.size()) {
    valid = validate_isbn_10(str);
  } else if (13 == str.size()) {
    valid = validate_isbn_13(str);
  }

  return valid;
}

int main() {
  string testISBN = "7301048157";
  cout << "Is ISBN number: " << validate_isbn_10(testISBN) << endl;
  string testISBN2 = "7-301-04815-7";
  cout << "Is ISBN number: " << validate_isbn_10(testISBN2) << endl;
  cout << "Is ISBN number: " << validate_isbn_with_hyphens(testISBN2) << endl;
  string testISBN13 = "9787301048153";
  cout << "Is ISBN-13 number: " << validate_isbn_13(testISBN13) << endl;
  string testISBN13_2 = "978-7-301-04815-3";
  cout << "Is ISBN-13 number: " << validate_isbn_with_hyphens(testISBN13)
       << endl;
  return 0;
}
