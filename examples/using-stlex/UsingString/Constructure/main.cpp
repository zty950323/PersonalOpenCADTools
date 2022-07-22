
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

// string构造函数的使用
void TzStringConstructureCase01() {
  string s1;  // 创建空字符串，调用无参构造函数
  cout << "str1 = " << s1 << endl;
  const char* str = "hello world, I am a C++ student.";
  string s2(str);  // 把c_string转换成了string
  cout << "str2 = " << s2 << endl;
  string s3(s2);  // 调用拷贝构造函数
  cout << "str3 = " << s3 << endl;
  string s4(10, 'a');  // 利用个数和字符创建重复的str
  cout << "str3 = " << s4 << endl;
  string s5(s4, 3, 5);  // 利用其它str的子串创建str
  cout << "str5 = " << s5 << endl;
  string s6(s4, 3);  // 利用其它str的子串创建str
  cout << "str6 = " << s6 << endl;
  string s7(s2, 3, 5);  // 利用有内容的str的子串创建str
  cout << "str7 = " << s7 << endl;
}

int main(int argc, char* argv[]) {
  TzStringConstructureCase01();

  system("pause");
  return 0;
}
