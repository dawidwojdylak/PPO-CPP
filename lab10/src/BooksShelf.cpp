#include <iostream> 
#include "BooksShelf.h"
#include "Book.h"
#include <string.h>

 using std::cout;
 using std::endl;

//fajen przyklad do przeanal
std::string fmt(size_t margin, size_t width, std::string text)
{
    std::string result;
    while (!text.empty())   // while more text to move into result
    {
        result += std::string(margin, ' ');  // add margin for this line

        if (width >= text.size())  // rest of text can fit... nice and easy
            return (result += text) += '\n';

        size_t n = width - 1;  // start by assuming we can fit n characters
        while (n > width / 2 && isalnum(text[n]) && isalnum(text[n - 1]))
            --n; // between characters; reduce n until word breaks or 1/2 width left

        // move n characters from text to result...
        (result += text.substr(0, n)) += '\n';
        text.erase(0, n);
    }
    return result;
}

  BooksShelf::BooksShelf(int numberOfShelves)
  {
    /*_shelfSize = numberOfShelves;*/
    _counter = 0;
  }

  void BooksShelf::add(Book book)
  {
    _allBooks[_counter] = book;
    _counter++;
    return;
  }

  void BooksShelf::remove(int n)
  {
    if(n > _counter)
    {
      cout << "!!! Nie mozna usunac ksiazki spoza polki !!! (element "
      << n << ")\n";
      return;
    }

    else
    {
      //tymczasowa tablica
      Book temp[MAX_SIZE];
      //iteratory
      //i dla temp, j dla _allBooks, aby ominac element 
      int i = 0, j = 0;
      while(i <= _counter)
      {
        //jesli to ten indeks, to omin
        if(i == n)
        {
          j++;
          _counter--; 
        }
        // zapisz do tymczasowej tablicy 
        temp[i] = _allBooks[j];
        i++;
        j++;
      }
      //skopiuj nowa tablice do starej
      for(i = 0; i < _counter; i++)
        _allBooks[i] = temp[i];
    }


  }
  void BooksShelf::print() const
  {
    //najpierw wysrodkuje tekst
    int maxLengthOfBookTitle = 0;
    //szukam najdluzszego tytulu
    for(int i = 0; i < _counter; i++)
      if(maxLengthOfBookTitle < _allBooks[i]._BookTitle.length())
        maxLengthOfBookTitle = _allBooks[i]._BookTitle.length();

    for(int i = 0; i < _counter; i++)
    {
     
      for(int j = 0; j < 
        (maxLengthOfBookTitle - _allBooks[i]._BookTitle.length() + 1) / 2; j++)
        cout << " ";
      cout << _allBooks[i]._BookTitle << endl;
    }
  }