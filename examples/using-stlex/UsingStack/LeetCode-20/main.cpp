
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stack>
#include <unordered_map>

using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::unordered_map;

class Solution {
 public:
  bool isValid(string s) {
    size_t n = s.size();
    if (n % 2 == 1) {
      return false;
    }
    unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
    stack<char> stk;
    for (char ch : s) {
      if (pairs.count(ch)) {
        if (stk.empty() || stk.top() != pairs[ch]) {
          return false;
        }
        stk.pop();
      } else {
        stk.push(ch);
      }
    }
    return stk.empty();
  }
};

void perpareTestData() {
  Solution s;
  cout << s.isValid("()") << endl;
  cout << s.isValid("()[]{}") << endl;
  cout << s.isValid("(]") << endl;
  cout << s.isValid("([)]") << endl;
  cout << s.isValid("{[]}") << endl;
  cout << s.isValid("") << endl;
  cout << s.isValid("(") << endl;
  cout << s.isValid(")") << endl;
  cout << s.isValid("[") << endl;
  cout << s.isValid("]") << endl;
  cout << s.isValid("{") << endl;
  cout << s.isValid("}") << endl;
  cout << s.isValid("({") << endl;
  cout << s.isValid("}(") << endl;
  cout << s.isValid("[}") << endl;
  cout << s.isValid("{]") << endl;
  cout << s.isValid("[(22])") << endl;
  cout << s.isValid("[(3]32)") << endl;
  cout << s.isValid("[(ds]ss)") << endl;
  cout << s.isValid("[ss(s]22)") << endl;
  cout << s.isValid("[(22]ss)") << endl;
}

int main(int argc, char* argv[]) {
  perpareTestData();
  system("pause");
  return 0;
}
