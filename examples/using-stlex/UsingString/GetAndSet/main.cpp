
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

// string 获取和设置字符的操作的使用
void TzStringGetAndSetCase01() {
  string str = "hello world";
  for (int i = 0; i < str.size(); i++) {
    cout << str[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < str.size(); i++) {
    cout << str.at(i) << " ";
  }
  cout << endl;

  // 字符修改
  str[0] = 'x';
  str.at(1) = 'x';
  cout << str << endl;

  // 迭代器遍历
  for (auto c : str) {
    cout << c << " ";
  }
  cout << endl;

  // 迭代器修改
  int i = 0;
  for (auto& c : str) {
    c = 'x' - i;
    i++;
  }
  cout << str << endl;
}

int main(int argc, char* argv[]) {
  TzStringGetAndSetCase01();
  system("pause");
  return 0;
}
