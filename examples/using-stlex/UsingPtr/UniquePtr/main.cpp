
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <memory>
#include <vector>

#include "UsingSTLExCommon.h"

using std::make_unique;
using std::move;
using std::unique_ptr;
using std::vector;
using std::wcout;

namespace {
unique_ptr<PtrCaseSong> SongFactory(const std::wstring& artist,
                                    const std::wstring& title) {
  // Implicit move operation into the variable that stores the result.
  return make_unique<PtrCaseSong>(artist, title);
}

void MakeSongs() {
  // Create a new unique_ptr with a new object.
  auto song = make_unique<PtrCaseSong>(L"Mr. Children", L"Namonaki Uta");
  // Use the unique_ptr.
  vector<wstring> titles = {song->title};
  // Move raw pointer from one unique_ptr to another.
  unique_ptr<PtrCaseSong> song2 = move(song);
  // Obtain unique_ptr from function that returns by value.
  auto song3 = SongFactory(L"Michael Jackson", L"Beat It");
}

void SongVector() {
  vector<unique_ptr<PtrCaseSong>> songs;

  // Create a few new unique_ptr<PtrCaseSong> instances
  // and add them to vector using implicit move semantics.
  songs.push_back(make_unique<PtrCaseSong>(L"B'z", L"Juice"));
  songs.push_back(make_unique<PtrCaseSong>(L"Namie Amuro", L"Funky Town"));
  songs.push_back(
      make_unique<PtrCaseSong>(L"Kome Kome Club", L"Kimi ga Iru Dake de"));
  songs.push_back(make_unique<PtrCaseSong>(L"Ayumi Hamasaki", L"Poker Face"));

  // Pass by const reference when possible to avoid copying.
  for (const auto& song : songs) {
    wcout << L"Artist: " << song->artist << L"   Title: " << song->title
          << endl;
  }
}

// using unique_ptr in some class.
class testClass {
 public:
  testClass(const std::wstring& artist, const std::wstring& title)
      : m_song(SongFactory(artist, title)) {}

  void useSong() { m_song->printSong(); }

 private:
  // this class owns a song unique_ptr.
  unique_ptr<PtrCaseSong> m_song;
};

struct Sample {
  int content_;
  explicit Sample(int content) : content_(content) {
    cout << "Constructing Sample(" << content_ << ")" << endl;
  }
  ~Sample() { cout << "Deleting Sample(" << content_ << ")" << endl; }
};

void ReleaseUniquePointer() {
  // Use make_unique function when possible.
  auto up1 = make_unique<Sample>(3);
  auto up2 = make_unique<Sample>(42);

  // Take over ownership from the unique_ptr up2 by using release
  auto ptr = up2.release();
  if (up2) {
    // This statement does not execute, because up2 is empty.
    cout << "up2 is not empty." << endl;
  }
  // We are now responsible for deletion of ptr.
  delete ptr;
  // up1 deletes its stored pointer when it goes out of scope.
}

// There is also a special case of copy prohibition semantics, that is, an
// std::unique_ptr can be returned ghrough a function.
unique_ptr<int> retUnique(int val) {
  unique_ptr<int> up(new int(val));
  return up;
}

/* Since unique pointers cannot be copied, how to transfer the heap memory held
 * by one unique pointer object to another? The answer is to use mobile
 * construction. The example code is as follows:*/
void useMoveUnique() {
  unique_ptr<int> up1(make_unique<int>(123));
  unique_ptr<int> up2(move(up1));
  cout << ((up1.get() == nullptr) ? "up1 is NULL" : "up1 is not NULL") << endl;

  unique_ptr<int> up3;
  up3 = move(up2);
  cout << ((up2.get() == nullptr) ? "up2 is NULL" : "up2 is not NULL") << endl;
  cout << *up3.get() << endl;
}

// we can use make_unique to create a unique_ptr to an array, but we cannot use
// make_unique to initialize the array elements.
void testUniqueArray() {
  // Create a unique_ptr to an array of 5 integers.
  auto p = make_unique<int[]>(5);
  // Initialize the array.
  for (int i = 0; i < 5; ++i) {
    p[i] = i;
    wcout << p[i] << endl;
  }
}

// you can hold not only one heap object, but also a group of heap
// objects.Examples are as follows:
void useUniqueArray() {
  // to create 10 heap objects of type int
  // type 1:
  unique_ptr<int[]> up1(new int[10]);
  // type 2:
  unique_ptr<int[]> up2;
  up2.reset(new int[10]);
  // type 3:
  unique_ptr<int[]> up3(make_unique<int[]>(10));

  for (int i = 0; i < 10; ++i) {
    up1[i] = i;
    up2[i] = i;
    up3[i] = i;
  }

  for (int i = 0; i < 10; ++i) {
    cout << up1[i] << ", " << up2[i] << ", " << up3[i] << endl;
  }
}

class TestSocket {
 public:
  TestSocket() { cout << "init the socket." << endl; }
  ~TestSocket() { cout << "destory the socket" << endl; }
  // close the handle of resource
  void close() { cout << "To Close the socket." << endl; }
};

void uniqueSocketCase() {
  auto deletor = [](TestSocket* pSocket) {
    // close the handle.
    pSocket->close();
    // To print some log.
    cout << "Log::Socket: after close socket." << endl;
    delete pSocket;
  };
  unique_ptr<TestSocket, void (*)(TestSocket * pSocket)> upSocket(
      new TestSocket(), deletor);
  unique_ptr<TestSocket, decltype(deletor)> upSocket1(new TestSocket(),
                                                      deletor);
}

}  // namespace

int main(int argc, char* argv[]) {
  MakeSongs();
  SongVector();
  testClass t(L"Michael Jackson", L"Beat It");
  t.useSong();
  ReleaseUniquePointer();
  unique_ptr<int> up1 = retUnique(123);
  cout << *up1.get() << endl;
  uniqueSocketCase();
  system("pause");
  return 0;
}
