
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

// string 查找和替换操作的使用
void TzStringFindAndReplaceCase01() {
  // 查找
  string str1 = "abcdefgde";
  auto pos = str1.find("de");
  if (-1 == pos) {
    cout << "not found" << endl;
  } else {
    cout << "pos = " << pos << endl;
  }
  pos = str1.rfind("de");
  cout << "pos = " << pos << endl;
}

void TzStringFindAndReplaceCase02() {
  // 替换
  string str1 = "abcdefgde";
  str1.replace(1, 3, "1111");
  cout << "str1 = " << str1 << endl;
  string str2 = "I am a coder, please remember me!";
  str2.replace(str2.find("coder"), 5, "Coder");
  cout << "str2 = " << str2 << endl;
  str2.replace(str2.find("please"), 5, "Please");
  cout << "str2 = " << str2 << endl;
}

int main(int argc, char* argv[]) {
  TzStringFindAndReplaceCase01();
  TzStringFindAndReplaceCase02();

  system("pause");
  return 0;
}
