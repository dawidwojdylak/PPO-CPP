#pragma once

namespace mystring
{
  /*
    To do
    są wycieki pamięci
  */

  class MyString
  {
    public:
      // konstruktory
      MyString(const char * arg = "");
      // konstruktor kopiujacy
      MyString(const MyString &s);
      // konstruktor przenoszący
      MyString(MyString &&s);
      // destruktor
      ~MyString();
      
      //metody
      // wypisuje string na ekran, poprzedza go cstringiem podanym jako argument
      void print(const char *txt = "") const;
      // porownuje dwa stringi typu MyString
      bool operator==(const MyString &s2) const;
      // porownuje dwa stringu typu MyString oraz const char*
      bool operator==(const char * txt) const;
      //THE RULE OF 3
      // operator przypisania
      MyString operator=(const char *txt);
      // rzutowanie
      operator char*() const;
      // metoda dodajaca do siebie dwa stringi typu MyString
      MyString operator+(const MyString &s) const;
      // metoda dodajaca do siebie dwa stringi typu MyString oraz const char *
      MyString operator+(const char * txt) const;
      // metoda dodajaca do string typu MyString znak typu char
      MyString operator+(const char c) const;
      // getter dla elementu _string
      const char * getString() const;
      // getter dla elementu _length
      unsigned int getLength() const;

    private:
      // główna zawartość stringa
      char * _string;
      // długość stringa
      unsigned int _length;
  };

  typedef MyString String;
  // Funkcja powielająca string typu MyString
  MyString operator*(int n, const MyString string);

}