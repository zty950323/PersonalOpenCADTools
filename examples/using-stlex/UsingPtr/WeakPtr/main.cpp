///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "UsingSTLExCommon.h"

using std::boolalpha;
using std::cout;
using std::endl;
using std::make_shared;
using std::pair;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::vector;
using std::weak_ptr;
using std::wstring;

namespace {
// use weak_ptr to get some other shared_ptr
void initWeakPtrCase() {
  // To create a shared_ptr object.
  shared_ptr<int> sp1(new int(123));
  cout << "use count: " << sp1.use_count() << endl;
  // Get an weak_ptr object through the constructor.
  weak_ptr<int> sp2(sp1);
  cout << "use count: " << sp1.use_count() << endl;
  // Get an weak_ptr object through the assignment operator.
  weak_ptr<int> sp3 = sp1;
  cout << "use count: " << sp1.use_count() << endl;
  // Get another object from one object.
  weak_ptr<int> sp4 = sp2;
  cout << "use count: " << sp1.use_count() << endl;
}

class A {
 public:
  void doSomething() { cout << "A is do something." << endl; }
};

void useWeakPtrCase() {
  std::shared_ptr<A> sp1(new A());
  std::weak_ptr<A> sp2(sp1);
  cout << "use count: " << sp1.use_count() << endl;
  // right code.
  if (sp1) {
    // right code.
    sp1->doSomething();
    (*sp1).doSomething();
    cout << "use count: " << sp1.use_count() << endl;
  }

  // right code.
  if (!sp1) {
    cout << "use count: " << sp1.use_count() << endl;
    return;
  }

  // Error code, unable to compile
  // if (sp2)
  // {
  //     // Error code, unable to compile
  //     sp2->doSomething();
  //     (*sp2).doSomething();
  // }

  // Error code, unable to compile
  // if (!sp2) {}

  if (sp2.expired()) {
    cout << "use count: " << sp1.use_count() << endl;
    cout << "sp2 is expired." << endl;
    return;
  }

  shared_ptr<A> sp3 = sp2.lock();
  if (sp3) {
    sp3->doSomething();
    (*sp3).doSomething();
    cout << "use count: " << sp1.use_count() << endl;
  }
}

class Subscriber {
 public:
  void sendMessage() { cout << "Subcriber gets an message." << endl; }
};

class SubscriberManager {
 public:
  void publish() {
    for (const auto& iter : m_subscribers) {
      if (!iter.expired()) {
        iter.lock()->sendMessage();
      }
    }
  }

  vector<weak_ptr<Subscriber>> m_subscribers;
};

constexpr size_t SubsLenth = 2;

void useSubscribeManager() {
  // The following code is an example of an error using a shared pointer.
  vector<shared_ptr<Subscriber>> subscribers;
  for (size_t i = 0; i < SubsLenth; i++) {
    subscribers.push_back(make_shared<Subscriber>());
  }

  for (auto sub : subscribers) {
    cout << sub.use_count() << endl;
  }

  SubscriberManager manager;
  for (auto sub : subscribers) {
    weak_ptr<Subscriber> wpSub(sub);
    manager.m_subscribers.push_back(wpSub);
  }

  cout << "Before reset:" << endl;
  for (auto sub : subscribers) {
    cout << sub.use_count() << endl;
  }
  cout << "Manager begin publish:" << endl;
  manager.publish();
  cout << "Manager end publish:" << endl;

  for (auto sub : subscribers) {
    sub.reset();
  }

  cout << "After reset:" << endl;
  cout << "Manager begin publish:" << endl;
  manager.publish();
  cout << "Manager end publish:" << endl;
  for (auto sub : subscribers) {
    cout << sub.use_count() << endl;
  }
}

void countPtrLength() {
  shared_ptr<int> sp0;
  shared_ptr<std::string> sp1;
  sp1.reset(new std::string());
  unique_ptr<int> sp2;
  weak_ptr<int> sp3;
  cout << "sp0 size: " << sizeof(sp0) << endl;
  cout << "sp1 size: " << sizeof(sp1) << endl;
  cout << "sp2 size: " << sizeof(sp2) << endl;
  cout << "sp3 size: " << sizeof(sp3) << endl;
}

void usePtrCase01() {
  Subscriber* pSubscriber = new Subscriber();
  unique_ptr<Subscriber> spSubscriber(pSubscriber);
  if (spSubscriber.get()) {
    spSubscriber->sendMessage();
  }
  // if user delete pointer, it will be crashed.
  // delete pSubscriber;
  // pSubscriber = nullptr;
  spSubscriber.reset();
  if (spSubscriber.get()) {
    spSubscriber->sendMessage();
  }
  spSubscriber.release();
  if (spSubscriber.get()) {
    spSubscriber->sendMessage();
  }
}

void usePtrCase02() {
  Subscriber* pSubscriber = new Subscriber();
  unique_ptr<Subscriber> spSubscriber(pSubscriber);
  Subscriber* pTheSameSubscriber = spSubscriber.get();
  spSubscriber->sendMessage();
  pTheSameSubscriber->sendMessage();
}

class T {
 public:
  void doSomething() { cout << "T do something..." << m_i << endl; }

 private:
  int m_i;
};

void usePtrCase03() {
  shared_ptr<T> sp1(new T());
  const auto& sp2 = sp1;
  sp1.reset();
  // Because SP2 no longer holds the reference of the object, the program will
  // have unexpected behavior here(crashed).
  // sp2->doSomething();
  // so we use:
  if (sp2.get()) {
    sp2->doSomething();
  }
}

void use_element_type_case() {
  shared_ptr<int> sp0(new int(5));
  weak_ptr<int> wp0(sp0);
  weak_ptr<int>::element_type val = *wp0.lock();
  cout << "*wp0.lock() == " << val << endl;
}

void use_expired_and_lock_case() {
  weak_ptr<int> wp;
  {
    shared_ptr<int> sp(new int(10));
    wp = sp;
    cout << "wp.expired() == " << boolalpha << wp.expired() << endl;
    cout << "*wp.lock() == " << *wp.lock() << endl;
  }
  // check expired after sp is destroyed.
  cout << "wp.expired() == " << boolalpha << wp.expired() << endl;
  cout << "(bool)wp.lock() == " << boolalpha << (bool)wp.lock() << endl;
}

void use_operator_equal_case() {
  shared_ptr<int> sp0(new int(5));
  weak_ptr<int> wp0(sp0);
  cout << "*wp0.lock() == " << *wp0.lock() << endl;
  shared_ptr<int> sp1(new int(10));
  wp0 = sp1;
  cout << "*wp0.lock() == " << *wp0.lock() << endl;
  weak_ptr<int> wp1;
  wp1 = wp0;
  cout << "*wp1.lock() == " << *wp1.lock() << endl;
}

void use_reset_case() {
  shared_ptr<int> sp(new int(5));
  weak_ptr<int> wp(sp);
  cout << "*wp.lock() == " << *wp.lock() << endl;
  cout << "wp.expired() == " << boolalpha << wp.expired() << endl;
  wp.reset();
  cout << "wp.expired() == " << boolalpha << wp.expired() << endl;
}

void use_swap_case() {
  shared_ptr<int> sp1(new int(5));
  shared_ptr<int> sp2(new int(10));
  cout << "*sp1 == " << *sp1 << endl;
  sp1.swap(sp2);
  cout << "*sp1 == " << *sp1 << endl;
  swap(sp1, sp2);
  cout << "*sp1 == " << *sp1 << endl;
  cout << endl;
  weak_ptr<int> wp1(sp1);
  weak_ptr<int> wp2(sp2);
  cout << "*wp1 == " << *wp1.lock() << endl;
  wp1.swap(wp2);
  cout << "*wp1 == " << *wp1.lock() << endl;
  swap(wp1, wp2);
  cout << "*wp1 == " << *wp1.lock() << endl;
}

void use_use_count_case() {
  shared_ptr<int> sp1(new int(5));
  weak_ptr<int> wp(sp1);
  cout << "wp.use_count() == " << wp.use_count() << endl;
  shared_ptr<int> sp2(sp1);
  cout << "wp.use_count() == " << wp.use_count() << endl;
}

void use_constructor_case() {
  weak_ptr<int> wp0;
  cout << "wp0.expired() == " << boolalpha << wp0.expired() << endl;
  shared_ptr<int> sp1(new int(5));
  weak_ptr<int> wp1(sp1);
  cout << "*wp1.lock() == " << *wp1.lock() << endl;
  weak_ptr<int> wp2(wp1);
  cout << "*wp2.lock() == " << *wp2.lock() << endl;
}

}  // namespace

int main(int argc, char* argv[]) {
  initWeakPtrCase();
  useWeakPtrCase();
  useSubscribeManager();
  countPtrLength();
  usePtrCase01();
  usePtrCase02();
  usePtrCase03();
  use_element_type_case();
  use_expired_and_lock_case();
  use_operator_equal_case();
  use_reset_case();
  use_swap_case();
  use_use_count_case();
  use_constructor_case();
  system("pause");
  return 0;
}
