#pragma once
#include <iostream>
class TString 
{
private:
  char* str;
  int len;
  int buffer = 0;
  int splitcount;
  int countFinds;
public:
  TString();
  TString(const char* c);
  TString(int n, char c = 0);
  TString(const TString& p);
  ~TString();
  int GetLen();
  TString operator +( const TString& p);
  TString& operator =(const TString& p);
  TString& operator +=(TString& p);
  TString operator +(char* s);
  TString operator = (char* s);
  TString operator += (char* s);
  friend std::ostream & operator <<(std::ostream& A, TString& p);
  friend std::istream & operator >> (std::istream& A, TString& p);
  bool operator == (TString& p);
  bool operator != (TString& p);
  bool operator > (TString& p);
  bool operator < (TString& p);
  char& operator [] (int i);
  int Find(char c);
  int* Find(TString& s);
  TString* Split(char c);
  int CStrLen(const char* s) const;
  void SetBuffer(int n, bool force = false);
  void ExtendBuffer(int n);
  void FreeBuffer();
  void Free();
  void SetCount(int count);
  int GetCount();
  void SetCountOfFindIndexes(int count);
  int GetCountOfFindIndexes();
};