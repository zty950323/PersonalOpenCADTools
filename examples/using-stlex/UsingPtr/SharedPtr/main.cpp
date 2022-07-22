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
using std::unique_ptr;
using std::vector;
using std::weak_ptr;
using std::wstring;

namespace {
// The following codes are mainly from Microsoft's official documents.
// https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-shared-ptr-instances?view=msvc-170
void initializeSharedPtr() {
  // Example for one.
  // Use make_shared function when possible.
  auto sp1 = make_shared<PtrCaseSong>(L"The Beatles",
                                      L"Im Happy Just to Dance With You");
  // Ok, but slightly less efficient.
  // Note: Using new expression as constructor argument
  // creates no named variable for other code to access.
  shared_ptr<PtrCaseSong> sp2(new PtrCaseSong(L"Lady Gaga", L"Just Dance"));

  // When initialization must be separate from declaration, e.g. class members,
  // initialize with nullptr to make your programming intent explicit.
  shared_ptr<PtrCaseSong> sp5(nullptr);
  // Equivalent to: shared_ptr<Song> sp5;
  // ...
  sp5 = make_shared<PtrCaseSong>(L"Elton John", L"I'm Still Standing");

  // example for two.
  // Initialize with copy constructor. Increments ref count.
  auto sp3(sp2);

  // Initialize via assignment. Increments ref count.
  auto sp4 = sp2;

  // Initialize with nullptr. sp7 is empty.
  shared_ptr<PtrCaseSong> sp7(nullptr);

  // Initialize with another shared_ptr. sp1 and sp2
  // swap pointers as well as ref counts.
  sp1.swap(sp2);
}

void useShardVector() {
  vector<shared_ptr<PtrCaseSong>> v{
      make_shared<PtrCaseSong>(L"Bob Dylan", L"The Times They Are A Changing"),
      make_shared<PtrCaseSong>(L"Aretha Franklin",
                               L"Bridge Over Troubled Water"),
      make_shared<PtrCaseSong>(L"Thalia", L"Entre El Mar y Una Estrella")};

  vector<shared_ptr<PtrCaseSong>> v2;
  // This step will remove Bob Dylan from the vector.
  remove_copy_if(v.begin(), v.end(), back_inserter(v2),
                 [](shared_ptr<PtrCaseSong> s) {
                   return s->artist.compare(L"Bob Dylan") == 0;
                 });

  for (const auto& s : v2) {
    wcout << s->artist << L":" << s->title << endl;
  }
}

void useCastInShardPtr() {
  vector<shared_ptr<MediaAsset>> assets{
      make_shared<PtrCaseSong>(L"Himesh Reshammiya", L"Tera Surroor"),
      make_shared<PtrCaseSong>(L"Penaz Masani", L"Tu Dil De De"),
      make_shared<Photo>(L"2011-04-06", L"Redmond, WA",
                         L"Soccer field at Microsoft."),
      make_shared<Photo>(L"2022-03-15", L"Wuhan, China",
                         L"Soccer filed at Home.")};
  // In this way, you can take out the objects of photo type in assets
  // separately.
  vector<shared_ptr<MediaAsset>> photos;
  copy_if(assets.begin(), assets.end(), back_inserter(photos),
          [](shared_ptr<MediaAsset> p) -> bool {
            // Use dynamic_pointer_cast to test whether
            // element is a shared_ptr<Photo>.
            shared_ptr<Photo> temp = dynamic_pointer_cast<Photo>(p);
            return temp.get() != nullptr;
          });
  for (const auto& p : photos) {
    // We know that the photos vector contains only
    // shared_ptr<Photo> objects, so use static_cast.
    wcout << "Photo location: " << (static_pointer_cast<Photo>(p))->location
          << endl;
  }
}

void useComparisonOperation() {
  // Initialize two separate raw pointers.
  // Note that they contain the same values.
  auto song1 = new PtrCaseSong(L"Village People", L"YMCA");
  auto song2 = new PtrCaseSong(L"Village People", L"YMCA");

  // Create two unrelated shared_ptrs.
  shared_ptr<PtrCaseSong> p1(song1);
  shared_ptr<PtrCaseSong> p2(song2);

  // Unrelated shared_ptrs are never equal.
  wcout << "p1 < p2 = " << boolalpha << (p1 < p2) << endl;
  wcout << "p1 == p2 = " << boolalpha << (p1 == p2) << endl;

  // Related shared_ptr instances are always equal.
  shared_ptr<PtrCaseSong> p3(p2);
  wcout << "p3 == p2 = " << boolalpha << (p3 == p2) << endl;
}

class F {};
class G : public F {};
typedef pair<int, int> myPair;

struct deleter {
  void operator()(int* p) { delete p; }
};

// using some function in shard_ptr
void useShardPtrFunc() {
  // use some constructor.
  shared_ptr<G> sp0(new G);  // okay, template parameter G and argument G*
  shared_ptr<G> sp1(
      sp0);  // okay, template parameter G and argument shared_ptr<G>
  shared_ptr<F> sp2(new G);  // okay, G* convertible to F*
  shared_ptr<F> sp3(
      sp0);  // okay, template parameter F and argument shared_ptr<G>
  shared_ptr<F> sp4(
      sp2);  // okay, template parameter F and argument shared_ptr<F>
  // shared_ptr<int> sp5(new G);  // error, G* not convertible to int*
  // shared_ptr<int> sp6(sp2);
  // error, template parameter int and argument shared_ptr<F>
  // use element_type().
  shared_ptr<int> sp00;
  shared_ptr<int> sp01(new int(5));
  shared_ptr<int> up(new int(10));
  shared_ptr<int>::element_type val = *sp01;
  cout << "*sp00 == " << val << std::endl;

  // for use get()
  cout << "sp00.get() == 0 == " << boolalpha << (sp00.get() == 0) << endl;
  cout << "*sp01.get() == " << *sp01.get() << endl;

  // to use operator bool. The operator returns a value of true when get() !=
  // nullptr, otherwise false.
  cout << "(bool)sp0 == " << boolalpha << (bool)sp00 << endl;
  cout << "(bool)sp1 == " << boolalpha << (bool)sp01 << endl;

  // to use operator*
  cout << "*sp01 == " << *sp01 << endl;

  // using operator=
  sp00 = sp01;
  cout << "*sp0 == " << *sp00 << endl;
  sp00 = up;
  cout << "*sp0 == " << *sp00 << endl;

  // using operator->
  shared_ptr<myPair> sp_pair(new myPair(1, 2));
  cout << "sp0->first == " << sp_pair->first << endl;
  cout << "sp0->second == " << sp_pair->second << endl;

  // using owner_before.
  cout << "sp00 is owner_before than sp01 == " << boolalpha
       << sp00.owner_before(sp01) << endl;
  cout << "sp01 is owner_before than sp00 == " << boolalpha
       << sp01.owner_before(sp00) << endl;

  // using reset.
  shared_ptr<int> sp(new int(5));
  cout << "*sp == " << boolalpha << *sp << endl;
  sp.reset();
  cout << "(bool)sp == " << boolalpha << (bool)sp << endl;
  sp.reset(new int(10));
  cout << "*sp == " << boolalpha << *sp << endl;
  sp.reset(new int(15), deleter());
  cout << "*sp == " << boolalpha << *sp << endl;
}

void useSomeConstructor() {
  shared_ptr<int> sp0;
  cout << "(bool)sp0 == " << boolalpha << (bool)sp0 << endl;
  shared_ptr<int> sp1(new int(5));
  cout << "*sp1 == " << *sp1 << endl;
  shared_ptr<int> sp2(new int(10), deleter());
  cout << "*sp2 == " << *sp2 << endl;
  shared_ptr<int> sp3(sp2);
  cout << "*sp3 == " << *sp3 << endl;
  weak_ptr<int> wp(sp3);
  shared_ptr<int> sp4(wp);
  cout << "*sp4 == " << *sp4 << endl;
  // unique_ptr<int> ap(new int(15));
  // shared_ptr<int> sp5(ap);  // error.
  // cout << "*sp5 == " << *sp5 << endl;
}

void useSomeDesructor() {
  shared_ptr<int> sp1(new int(5));
  cout << "*sp1 == " << *sp1 << endl;
  cout << "use count == " << sp1.use_count() << endl;
  {
    shared_ptr<int> sp2(sp1);
    cout << "*sp2 == " << *sp2 << endl;
    cout << "use count == " << sp1.use_count() << endl;
  }
  // check use count after sp2 is destroyed
  cout << "use count == " << sp1.use_count() << endl;
}

void useSwap() {
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

// there are some code from one article.
// https://blog.csdn.net/code_peak/article/details/119722167
void threeWayToInitSharedPtr() {
  // way 1
  shared_ptr<int> sp1(new int(123));
  cout << "*sp1 == " << *sp1 << endl;
  // way 2
  shared_ptr<int> sp2;
  sp2.reset(new int(123));
  cout << "*sp2 == " << *sp2 << endl;
  // way 3
  shared_ptr<int> sp3;
  sp3 = make_shared<int>(123);
  cout << "*sp3 == " << *sp3 << endl;
}

class A {
 public:
  A() { cout << "A constructor" << endl; }
  ~A() { cout << "A destructor" << endl; }
};

void useAInSharedPtr() {
  // way 1
  shared_ptr<A> sp1(new A());
  cout << "use count: " << sp1.use_count() << endl;
  // way 2
  shared_ptr<A> sp2(sp1);
  cout << "use count: " << sp1.use_count() << endl;
  sp2.reset();
  cout << "use count: " << sp1.use_count() << endl;
  {
    shared_ptr<A> sp3 = sp1;
    cout << "use count: " << sp1.use_count() << endl;
  }
  cout << "use count: " << sp1.use_count() << endl;
}

}  // namespace

int main(int argc, char* argv[]) {
  initializeSharedPtr();
  useShardVector();
  useCastInShardPtr();
  useComparisonOperation();
  useShardPtrFunc();
  useSomeConstructor();
  useSomeDesructor();
  useSwap();
  threeWayToInitSharedPtr();
  useAInSharedPtr();
  system("pause");
  return 0;
}
