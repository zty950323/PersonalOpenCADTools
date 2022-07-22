
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

// string Append操作的使用
void TzStringAppendCase01() {
  string str1("I");
  str1 += "Love to play the game";
  cout << "str1 = " << str1 << endl;
  str1 += ':';
  cout << "str1 = " << str1 << endl;
  string str2 = "Steam LOL DNF ....";
  str1 += str2;
  cout << "str1 = " << str1 << endl;
  string str3 = "I";
  str3.append(" love ");
  str3.append("game abcde", 4);
  // str3.append(str2);
  str3.append(str2, 4, 3);  // 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
  cout << "str3 = " << str3 << endl;
  string str4 = str3;
  str4 += str2;
  str4.append(str2, 2, 4);
  cout << "str4 = " << str4 << endl;
}

int main(int argc, char* argv[]) {
  TzStringAppendCase01();
  system("pause");
  return 0;
}
