
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <deque>
#include <iostream>

using std::cout;
using std::deque;
using std::endl;

void printDeque(const deque<int>& d) {
  for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void display_sizes(const std::deque<int>& nums1, const std::deque<int>& nums2,
                   const std::deque<int>& nums3) {
  std::cout << " nums1: " << nums1.size() << " nums2: " << nums2.size()
            << " nums3: " << nums3.size() << '\n';
}

// operator=
void TzDequeOperatorCase01() {
  deque<int> d1;
  for (int i = 0; i < 10; i++) {
    d1.push_back(i);
  }
  printDeque(d1);

  deque<int> d2;
  d2 = d1;
  printDeque(d2);

  deque<int> d3;
  d3.assign(d1.begin(), d1.end());
  printDeque(d3);

  deque<int> d4;
  d4.assign(10, 100);
  printDeque(d4);
}

// other operators.
void TzDequeOperatorCase02() {
  std::deque<int> nums1{3, 1, 4, 6, 5, 9};
  std::deque<int> nums2;
  std::deque<int> nums3;

  std::cout << "Initially:\n";
  display_sizes(nums1, nums2, nums3);

  // copy assignment copies data from nums1 to nums2
  nums2 = nums1;

  std::cout << "After assigment:\n";
  display_sizes(nums1, nums2, nums3);

  // move assignment moves data from nums1 to nums3,
  // modifying both nums1 and nums3
  nums3 = std::move(nums1);

  std::cout << "After move assigment:\n";
  display_sizes(nums1, nums2, nums3);
}

// using assignment operator
void TzDequeOperatorCase03() {
  std::deque<char> characters;
  auto print_deque = [&]() {
    for (char c : characters) std::cout << c << ' ';
    std::cout << '\n';
  };

  characters.assign(5, 'a');
  print_deque();

  const std::string extra(6, 'b');
  characters.assign(extra.begin(), extra.end());
  print_deque();

  characters.assign({'C', '+', '+', '1', '1'});
  print_deque();
}

int main() {
  TzDequeOperatorCase01();
  TzDequeOperatorCase02();
  TzDequeOperatorCase03();
  system("pause");
  return 0;
}
