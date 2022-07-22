
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::max;
using std::stack;
using std::string;

class Solution {
 public:
  int longestValidParentheses(string s) {
    int maxans = 0;
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        stk.push(i);
      } else {
        stk.pop();
        if (stk.empty()) {
          stk.push(i);
        } else {
          maxans = max(maxans, i - stk.top());
        }
      }
    }
    return maxans;
  }
};

void perpareTestData() {
  Solution s;
  string s1 = "()";
  cout << s.longestValidParentheses(s1) << endl;
  string s2 = ")()())";
  cout << s.longestValidParentheses(s2) << endl;
  string s3 = ")()())()())))))(";
  cout << s.longestValidParentheses(s3) << endl;
  string s4 = ")()())()()))))()())()()()()";
  cout << s.longestValidParentheses(s4) << endl;
  string s5 = ")()())(())))(()()()()())))))()()()";
  cout << s.longestValidParentheses(s5) << endl;
  string s6 = ")()())(()()())()()()()()()()()()(";
  cout << s.longestValidParentheses(s6) << endl;
  string s7 = ")()()))()()))()()()()))())()())()()()()())";
  cout << s.longestValidParentheses(s7) << endl;
  string s8 = ")()()))()()()())())()()()()()())))()())";
  cout << s.longestValidParentheses(s8) << endl;
  string s9 = ")()()())())())()))()()(((()()()()()()(((())";
  cout << s.longestValidParentheses(s9) << endl;
  string s10 = ")()())()()))())()()()()()()()()()()()()()()())";
}

int main(int argc, char* argv[]) {
  perpareTestData();
  system("pause");
  return 0;
}
