#pragma once
//#include "BooksShelf.h"
#include <string>

class BooksShelf;

//klasa reprezentujaca ksiazke
class Book
{
  friend BooksShelf;
public:
  //kontstruktor ustawiajacy tytul ksiazki
  Book(std::string title);
  //nic nie robi
  Book();
private:
  //tytul ksiazki
  //const char *_BookTitle;
	std::string _BookTitle;

};