#include "MyString.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

using namespace mystring;

MyString::MyString(const char * arg)
{
  //cout << "KONSTRUKOTR domyslny\n";
  //_string = (char *) arg; // powodowalo segmentation
  // fault przy zwalnianiu pamięci :)
  //_length = 0;
  //for (_length; arg[ _length ] != '\0'; ++_length);
  
  _length = strlen(arg);

  _string = new char[_length + 1];

  for (unsigned int i = 0; i < _length + 1; ++i)
    _string[i] = arg[i];
}

MyString::MyString(const MyString &s)
{
  //cout << "KONSTRUKOTR KOPIUJACY\n";
  _length = s._length;
  _string = new char[_length + 1];
  //for (unsigned int i = 0; i < _length + 1; i++)
  //  _string[i] = s._string[i];
  strcpy(_string, s._string);
}

MyString::MyString(MyString &&s)
{
  cout << "KONSTRUKOTR przenoszacy\n";
  _length = s._length;
  _string = new char[_length + 1];
  strcpy(_string, s._string);
  
  s._string = 0;
  s._length = 0;
}


MyString::~MyString()
{
  //cout << "DESTRUKTOR : " << _string << endl;
  delete []  _string;
  //_string = 0;
}


void MyString::print(const char * txt) const
{
  cout << txt << _string << "\n";
  //cout << _length << endl;
}
bool MyString::operator==(const MyString &s2) const
{
  if (_length != s2._length)
    return false;
  else 
  {
    for (unsigned int i = 0; i < _length; ++i)
      if (_string[i] != s2._string[i])
        return false;
  }
  return true;
}

bool MyString::operator==(const char * txt) const
{
  MyString temp(txt);
  return *this == temp;
}

MyString MyString::operator=(const char *txt)  
{
  // nie działa
/*  _length = strlen(txt) + 1;
  strcpy(_string, txt);*/
  MyString output;
  output._length = strlen(txt);
  output._string = new char[strlen(txt) + 1];
  strcpy(output._string, txt);
  return output;
}

MyString::operator char*() const
{
  return _string;
}

MyString MyString::operator+(const MyString &s) const
{
  unsigned int newSize = _length + s._length;
  MyString newString;
  newString._length = newSize;
  newString._string = new char[newSize + 1];

  strcpy(newString._string, _string);
  strcat(newString._string, s._string);
  return newString;
}

MyString MyString::operator+(const char * txt) const
{
  MyString output(txt);
  return *this + output;
}

MyString MyString::operator+(const char c) const
{
  // converting char to c-string
  const char * txt = &c;
  //const char *txt = (const char *) c;
  MyString output = MyString(txt);
  return *this + output;
}

const char * MyString::getString() const
{
  return _string;
}
unsigned int MyString::getLength() const
{
  return _length;
} 

MyString mystring::operator*(int n, const MyString string)
{
  unsigned int len = string.getLength();
  const char * str = string.getString();

  char * newTxt = new char[len * n + n];


  strcpy(newTxt, str);
  for(int i = 0; i < n - 1; i++)
    strcat(newTxt, str);

  MyString output(newTxt);
  return output; 
}


