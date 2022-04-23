#include "String.h"
#include <cstring>
#include <iostream>
using std::ostream;
using std::istream;

int TString::Find(char c)
{
  for (int i = 0; i < len; i++)
  {
    if (str[i] == c)
    {
      return i;
    }
  }
  return -1;
}

int* TString::Find(TString& s)
{
  int* tmp = new int[len - 1];
  int count = 0;
  int k = 0;
  if (s.len> len)  
    throw "Word size is too big";
  for (int i = 0; i < len; i++)
  {
    bool flag = 1;
    for (int j = 0; j < s.len - 1; j++)
    {
      if (str[i + j] != s.str[j])
      {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      tmp[k] = i;
      k++;
      count++;
    }
  }
  if (k == 0) throw "No entry";
  int* ind = new int[count];
  for (int i = 0; i < count; i++)	ind[i] = tmp[i];
  delete[] tmp;
  SetCountOfFindIndexes(count);
  return ind;
}

TString* TString::Split(char c)
{
  int r = 0;
  for (int i = 0; i < len; i++)
  {
    if (str[i] == c)
    {
      r++;
    }
  }
  if (r == 0)
    return 0;
  r += 1;
  TString* mas = new TString[r];
  int j = 0;
  int start = 0;
  for (int i = 0; i < len; i++)
  {
    if (str[i] == c)
    {
      mas[j].len = i - start + 1;
      delete[] mas[j].str;
      mas[j].str = new char[mas[j].len];
      for (int k = 0; k < mas[j].len - 1; k++)
      {
        mas[j].str[k] = str[k + start];
      }
      mas[j].str[mas[j].len - 1] = 0;
      j++;
      start = i + 1;
    }
  }
  mas[j].len = len - start;
  delete[] mas[j].str;
  mas[j].str = new char[mas[j].len];
  for (int k = 0; k < mas[j].len; k++)
  {
    mas[j].str[k] = str[k + start];
  }
  mas[j].str[mas[j].len] = 0;
  j++;
  SetCount(r);
  return mas;
}

TString::TString()
{
  {
    str = new char[1];
    str = 0;
    len = 1;
  }
}

TString::TString(const char* c)
{
  if (c == 0)
    throw "err";
  int n = CStrLen(c);
  len = n;
  str = new char[len + 1];
  for (int i = 0; i < len; i++)
  {
    str[i] = c[i];
  }
  str[len] = 0;
}

TString::TString(int n, char c)
{
  if (n == 0)
    throw "Err";
  len = n + 1;
  str = new char[len];
  for (int i = 0; i < len; i++) 
  {
    str[i] = c;
  }
  str[len - 1] = 0;
}

TString::TString(const TString& p)
{
  len = p.len;
  str = new char[len + 1];
  for (int i = 0; i < len; i++) 
  {
    str[i] = p.str[i];
  }
  str[len] = 0;
}

TString::~TString()
{
  if (str != 0) 
  {
    delete[]str;
    str = 0;
  }
  
}

int TString::GetLen()
{
  return len;
}

TString TString::operator+(const TString& p)
{
  if (p.str == 0) 
    return *this;
  TString A;
  int l = len + p.len + 1;
  A.str = new char[l];
  A.len = l;
  for (int i = 0; i < len; i++)	
    A.str[i] = str[i];
  for (int i = 0; i < p.len; i++)
    A.str[i + len] = p.str[i];
  A.str[l - 1] = 0;
  return A;
}

TString& TString::operator=(const TString& p)
{
  if (this == &p)
    return *this;
  delete[]str;
  len = p.len;
  str = new char[len];
  for (int i = 0; i < len; i++) 
  {
    str[i] = p.str[i];
  }
  return *this;
}

TString& TString::operator+=(TString& p)
{
  int l = p.len + len + 1;
  char* c = new char[l];
  for (int i = 0; i < len; i++)
    c[i] = str[i];
  for (int i = 0; i < p.len; i++)
    c[i + len] = p.str[i];
  c[l - 1] = 0;
  delete[]str;
  str = c;
  len = l;
  return *this;
}


TString TString::operator+(char* s)
{
  if (s == 0)
    return *this;
  TString A;
  int l = len + CStrLen(s) + 1;
  A.str = new char[l];
  A.len = l;
  for (int i = 0; i < len; i++)
    A.str[i] = str[i];
  for (int j = 0; j < CStrLen(s); j++)
    A.str[j + len] = s[j];
  A.str[l - 1] = 0;
  return A;
}

TString TString::operator=(char* s)
{
  if (s == 0) 
  {
    throw "Err";
    delete[]s;
  }
  len = CStrLen(s) + 1;
  str = new char[len];
  for (int i = 0; i < len - 1; i++) 
  {
    str[i] = s[i];
  }
  str[len - 1] = 0;
  return *this;
}


TString TString::operator+=(char* s)
{
  if (s == 0)
    throw "Err";
  int l = CStrLen(s) + len + 1;
  char* c = new char[l];
  for (int i = 0; i < len; i++)
    c[i] = str[i];
  for (int i = 0; i < CStrLen(s); i++)
    c[i + len] = s[i];
  c[l - 1] = 0;
  delete[]str;
  str = c;
  len = l;
  return *this;
}

bool TString::operator==(TString& p)
{
  if (len != p.len)
    return false;
  for (int i = 0; i <= len; i++) 
  {
    if (str[i] != p.str[i])
      return false;
  }
  return true;
}

bool TString::operator!=(TString& p)
{
  if (len != p.len)
    return true;
  for (int i = 0; i < len; i++) 
  {
    if (str[i] != p.str[i])
      return true;
  }
  return false;
}

bool TString::operator>(TString& p)
{
  int l = len > p.len ? p.len : len;
  for (int i = 0; i < l; i++)
  {
    if (str[i] < p.str[i])
      return false;
    else if (str[i] > p.str[i])
      return true;
  }
  if (len >= p.len)
    return true;
  else
    return false;
}

bool TString::operator<(TString& p)
{
  int l = len > p.len ? p.len : len;
  for (int i = 0; i < l; i++)
  {
    if (str[i] < p.str[i])
      return true;
    else if (str[i] > p.str[i])
      return false;
  }
  if (len >= p.len)
    return false;
  else
    return true;
}

char& TString::operator[](int i)
{
  if (str == 0)
    throw "Err";
  if (i < 0 && len < i)
    throw "Err";
  return str[i];
}

std::ostream& operator<<(std::ostream& A, TString& p)
{
  A << p.str;
  return A;
}

std::istream& operator>>(std::istream& A, TString& p)
{
  const int STR_IN_BUFFER = 1024;
  char c;
  int i = 0, k = 0;
  p.len = 0;
  p.SetBuffer(STR_IN_BUFFER, true);
  while (A.get(c) && c != 10)
  {
    if (i >= STR_IN_BUFFER)
    {
      k++;
      i = 0;
      p.ExtendBuffer(STR_IN_BUFFER * (k + 1));
    }
    p.str[i + STR_IN_BUFFER * k] = c;
    p.len++;
    i++;
  }
  if (i >= STR_IN_BUFFER)
  {
    k++;
    p.len = STR_IN_BUFFER * k - 1;
    p.ExtendBuffer(STR_IN_BUFFER * k + 1);
    p.len++;
    p.str[STR_IN_BUFFER * k] = '\0';
  }
  else
  {
    p.str[i + STR_IN_BUFFER * k] = '\0';
    p.len = i + STR_IN_BUFFER * k;
    p.FreeBuffer();
  }
  return A;
}

int TString::CStrLen(const char* s) const
{
  const char* temp = s;
  while (*s)
    s++;
  return s - temp;
}

void TString::SetBuffer(int n, bool force)
{
  if (n > buffer || force)
  {
    Free();
    str = new char[n];
    buffer = n;
  }
}
void TString::ExtendBuffer(int n)
{
  if (n > buffer && n > len + 1)
  {
    char* tmp = new char[n];
    for (int i = 0; i < len + 1; i++)
      tmp[i] = str[i];
    Free();
    str = tmp;
    buffer = n;
  }
}
void TString::FreeBuffer()
{
  if (buffer > len + 1)
  {
    char* new_s = new char[len + 1];
    for (int i = 0; i < len + 1; i++)
    {
      new_s[i] = str[i];
    }
    Free();
    buffer = len + 1;
    str = new_s;
  }
}
void TString::Free()
{
  if (buffer)
    delete[] str;
}

void TString::SetCount(int count)
{
  splitcount = count;
}

int TString::GetCount()
{
  return splitcount;
}
void TString::SetCountOfFindIndexes(int count)
{
  countFinds = count;
}

int TString::GetCountOfFindIndexes()
{
  return countFinds;
}