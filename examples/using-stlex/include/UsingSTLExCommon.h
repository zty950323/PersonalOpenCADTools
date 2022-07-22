///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef D8061999_10B2_4E21_A26C_64A83EB0C7AF
#define D8061999_10B2_4E21_A26C_64A83EB0C7AF

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::wcout;
using std::wstring;

class UsingSTLExCommonUtility {
 public:
  inline static void Print(const string& str) { cout << str << endl; }
  inline static void Print(const char* str) { cout << str << endl; }
  inline static void Print(const char* str, int n) { cout << str << n << endl; }
  inline static void Print(const char* str, int n, int m) {
    cout << str << n << " " << m << endl;
  }
  inline static void Print(const char* str, int n, int m, int l) {
    cout << str << n << " " << m << " " << l << endl;
  }
};

struct MediaAsset {
  virtual ~MediaAsset() = default;  // make it polymorphic
};

struct PtrCaseSong : public MediaAsset {
  wstring artist;
  wstring title;

  PtrCaseSong(const std::wstring& artist_, const std::wstring& title_)
      : artist{artist_}, title{title_} {}
  inline void printSong() { wcout << artist << '\t' << title << endl; }
};

struct Photo : public MediaAsset {
  wstring date;
  wstring location;
  wstring subject;
  Photo(const wstring& date_, const wstring& location_, const wstring& subject_)
      : date{date_}, location{location_}, subject{subject_} {}
};

#endif /* D8061999_10B2_4E21_A26C_64A83EB0C7AF */
