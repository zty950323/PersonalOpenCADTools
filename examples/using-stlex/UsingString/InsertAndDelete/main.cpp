
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

// string 插入和删除字符的操作的使用
void TzStringInsertAndDeleteCase01() {
  string str = "hello";
  str.insert(1, "111");
  cout << str << endl;
  str.erase(1, 3);  // 从1号位置开始3个字符
  cout << str << endl;
  str.insert(str.length() - 2, "222");
  cout << str << endl;
  str.erase(str.length() - 2, 2);
  cout << str << endl;
}

int main(int argc, char* argv[]) {
  TzStringInsertAndDeleteCase01();
  system("pause");
  return 0;
}
