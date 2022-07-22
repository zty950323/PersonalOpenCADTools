
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

// string Compare操作的使用
void TzStringCompareCase01() {
  string s1 = "hello";
  string s2 = "aello";
  auto printRet = [](const string& s1, const string& s2, bool ret) {
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    if (0 == ret) {
      cout << "s1 equal s2" << endl;
    } else if (0 < ret) {
      cout << "s1 more than s2" << endl;
    } else {
      cout << "s1 less than s2" << endl;
    }
    cout << "ret: " << ret << endl;
  };
  int ret = s1.compare(s2);
  printRet(s1, s2, ret);
  cout << "s1.compare(s2) = " << ret << endl;
  // 比较函数的第一个参数是从哪个位置开始比较，第二个参数是比较的长度
  // 最终获取的是s1的前3个字符与s2的前3个字符的比较结果
  ret = s1.compare(0, 3, s2);
  printRet(s1, s2, ret);
}

int main(int argc, char* argv[]) {
  TzStringCompareCase01();

  system("pause");
  return 0;
}
