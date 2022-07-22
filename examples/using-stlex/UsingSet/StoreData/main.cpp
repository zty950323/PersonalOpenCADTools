
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;

namespace {
// print out a container
template <class Os, class K>
Os& operator<<(Os& os, const std::set<K>& v) {
  os << '[' << v.size() << "] {";
  bool o{};
  for (const auto& e : v) os << (o ? ", " : (o = 1, " ")) << e;
  return os << " }\n";
}
}  // namespace

// using merge
void useSetMergeCase01() {
  std::set<char> p{'C', 'B', 'B', 'A'}, q{'E', 'D', 'E', 'C'};
  std::cout << "p: " << p << "q: " << q;
  p.merge(q);
  std::cout << "p.merge(q);\n"
            << "p: " << p << "q: " << q;
}

int main(int argc, char* argv[]) {
  useSetMergeCase01();
  system("pause");
  return 0;
}
