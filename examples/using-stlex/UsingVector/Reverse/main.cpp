
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <cstddef>
#include <iostream>
#include <new>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

constexpr int kMaxSize = 100000;

// minimal C++11 allocator with debug output
template <class Tp>
struct NAlloc {
  typedef Tp value_type;
  NAlloc() = default;
  template <class T>
  NAlloc(const NAlloc<T>&) {}

  Tp* allocate(std::size_t n) {
    n *= sizeof(Tp);
    std::cout << "allocating " << n << " bytes\n";
    return static_cast<Tp*>(::operator new(n));
  }

  void deallocate(Tp* p, std::size_t n) {
    std::cout << "deallocating " << n * sizeof *p << " bytes\n";
    ::operator delete(p);
  }
};

template <class T, class U>
bool operator==(const NAlloc<T>&, const NAlloc<U>&) {
  return true;
}
template <class T, class U>
bool operator!=(const NAlloc<T>&, const NAlloc<U>&) {
  return false;
}

void TzVectorReverseCase01() {
  vector<int> v;
  // Reserved space
  v.reserve(kMaxSize);
  int num = 0;
  int* p = NULL;
  for (int i = 0; i < kMaxSize; i++) {
    v.push_back(i);
    if (p != &v[0]) {
      p = &v[0];
      num++;
    }
  }
  cout << "num:" << num << endl;
}

void TzVectorReverseCase02() {
  int sz = 100;
  std::cout << "using reserve: \n";
  {
    std::vector<int, NAlloc<int>> v1;
    v1.reserve(sz);
    for (int n = 0; n < sz; ++n) v1.push_back(n);
  }
  std::cout << "not using reserve: \n";
  {
    std::vector<int, NAlloc<int>> v1;
    for (int n = 0; n < sz; ++n) v1.push_back(n);
  }
}

int main(int argc, char* argv[]) {
  TzVectorReverseCase01();
  system("pause");
  return 0;
}
