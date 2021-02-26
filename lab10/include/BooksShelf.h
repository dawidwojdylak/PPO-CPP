#pragma once
#include "Book.h"
#include <string.h>
#define MAX_SIZE 50

//class Book;

std::string fmt(size_t margin, size_t width, std::string text);

class BooksShelf
{

public:
  //kontruktor ustawiajacy pojemnosc polki
  BooksShelf(int numberOfShelves = 5);
  //metoda dodajaca ksiazke typu class Book, ktora przyjmuje jako argument
  void add(Book book);
  //metoda usuwajaca n-ty element z polki
  void remove(int n);
  //metoda wypisujaca ksiazki z polki
  void print() const;

private:
  //rozmiar polki 
  int _counter; //liczy ile polek zajetych
  //tablica przechowujaca ksiazki typu class Book
  Book _allBooks[MAX_SIZE];

};

