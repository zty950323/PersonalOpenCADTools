
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// string 子串操作的使用
void TzStringSubStrCase01() {
  string str = "abcdefg";
  string subStr = str.substr(1, 3);
  cout << "subStr = " << subStr << endl;
  string email = "hello@sina.com";
  auto pos = email.find("@");
  string username = email.substr(0, pos);
  cout << "username: " << username << endl;
  string domain = email.substr(pos + 1);
  cout << "domain: " << domain << endl;
  // 可以看到，substr()函数返回的是一个新的字符串，而不是原来的字符串的一部分。
  string subStr2 = email.substr(pos + 1, 3).substr(0, 2);
  // subStr可以嵌套使用。
  cout << "subStr2: " << subStr2 << endl;
}

int main(int argc, char* argv[]) {
  TzStringSubStrCase01();

  system("pause");
  return 0;
}
