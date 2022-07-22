
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cassert>
#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>

using std::cout;
using std::endl;
using std::set;

namespace {
class Dew {
 private:
  int a;
  int b;
  int c;

 public:
  Dew(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}

  bool operator<(const Dew& other) const {
    if (a < other.a) return true;
    if (a == other.a && b < other.b) return true;
    return (a == other.a && b == other.b && c < other.c);
  }
};

constexpr int nof_operations = 120;

int set_emplace() {
  std::set<Dew> set;
  for (int i = 0; i < nof_operations; ++i)
    for (int j = 0; j < nof_operations; ++j)
      for (int k = 0; k < nof_operations; ++k) set.emplace(i, j, k);
  return set.size();
}

int set_insert() {
  std::set<Dew> set;
  for (int i = 0; i < nof_operations; ++i)
    for (int j = 0; j < nof_operations; ++j)
      for (int k = 0; k < nof_operations; ++k) set.insert(Dew(i, j, k));
  return set.size();
}

constexpr int nof_hint_operations = 100500;

int set_emplace_by_hint() {
  std::set<int> set;
  for (int i = 0; i < nof_hint_operations; ++i) {
    set.emplace(i);
  }
  return set.size();
}

int set_emplace_hint() {
  std::set<int> set;
  auto it = set.begin();
  for (int i = 0; i < nof_hint_operations; ++i) {
    set.emplace_hint(it, i);
    it = set.end();
  }
  return set.size();
}

int set_emplace_hint_wrong() {
  std::set<int> set;
  auto it = set.begin();
  for (int i = nof_hint_operations; i > 0; --i) {
    set.emplace_hint(it, i);
    it = set.end();
  }
  return set.size();
}

int set_emplace_hint_corrected() {
  std::set<int> set;
  auto it = set.begin();
  for (int i = nof_hint_operations; i > 0; --i) {
    set.emplace_hint(it, i);
    it = set.begin();
  }
  return set.size();
}

int set_emplace_hint_closest() {
  std::set<int> set;
  auto it = set.begin();
  for (int i = 0; i < nof_hint_operations; ++i) {
    it = set.emplace_hint(it, i);
  }
  return set.size();
}

void timeit(std::function<int()> set_test, std::string what = "") {
  auto start = std::chrono::system_clock::now();
  int setsize = set_test();
  auto stop = std::chrono::system_clock::now();
  std::chrono::duration<double, std::milli> time = stop - start;
  if (what.size() > 0 && setsize > 0) {
    std::cout << std::fixed << std::setprecision(2) << time.count()
              << "  ms for " << what << '\n';
  }
}

}  // namespace

// using insert
void useSetCase01() {
  std::set<int> set;
  auto result_1 = set.insert(3);
  assert(result_1.first != set.end());  // it's a valid iterator
  assert(*result_1.first == 3);
  if (result_1.second) std::cout << "insert done\n";
  auto result_2 = set.insert(3);
  assert(result_2.first == result_1.first);  // same iterator
  assert(*result_2.first == 3);
  if (!result_2.second) std::cout << "no insertion\n";
}

// using clear
void useSetCase02() {
  std::set<int> container{1, 2, 3};
  auto print = [](const int& n) { std::cout << " " << n; };
  std::cout << "Before clear:";
  std::for_each(container.begin(), container.end(), print);
  std::cout << "\nSize=" << container.size() << '\n';
  std::cout << "Clear\n";
  container.clear();
  std::cout << "After clear:";
  std::for_each(container.begin(), container.end(), print);
  std::cout << "\nSize=" << container.size() << '\n';
}

// using earse
void useSetCase03() {
  std::set<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  // erase all odd numbers from c.
  for (auto it = c.begin(); it != c.end();) {
    if (*it % 2 != 0)
      it = c.erase(it);
    else
      ++it;
  }
  for (int n : c) {
    std::cout << n << ' ';
  }
}

// using emplace
void useSetCase04() {
  set_insert();
  timeit(set_insert, "insert");
  timeit(set_emplace, "emplace");
  timeit(set_insert, "insert");
  timeit(set_emplace, "emplace");
}

// using emplace_hint
void useSetCase05() {
  timeit(set_emplace_by_hint);  // stack warmup
  timeit(set_emplace_by_hint, "plain emplace");
  timeit(set_emplace_hint, "emplace with correct hint");
  timeit(set_emplace_hint_wrong, "emplace with wrong hint");
  timeit(set_emplace_hint_corrected, "corrected emplace");
  timeit(set_emplace_hint_closest, "emplace using returned iterator");
}

int main(int argc, char* argv[]) {
  useSetCase01();
  useSetCase02();
  useSetCase03();
  useSetCase04();
  useSetCase05();
  system("pause");
  return 0;
}
