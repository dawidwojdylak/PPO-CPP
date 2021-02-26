#include <iostream>
#include <initializer_list>
#include <utility> // for std::exchange;
#include "MyList.h"

using std::cout;
using std::endl;

//prints in green
void printHeaderInColor(const char * line)
{
    std::cout << "\033[1;32m\n" << line << "\033[0m" << std::endl;
}
//prints in red
void printLineInColor(const char * line)
{
    std::cout << "\033[1;31m" << line << "\033[0m";
}

///////////////////////////////////////////////////////////////
//konstruktory

// konstruktor domyslny
MyList::MyList()
{
  //cout << "KONST: Domyslny\n";
  printLineInColor("KONST: Domyslny\n");
}

// konstruktor jednoargumentowy
MyList::MyList(int n)
{
  //cout << "KONST: jednoargumentowy\n";
  printLineInColor("KONST: jednoargumentowy\n");
  _listSize = n;

  MyNode *firstEl = new MyNode;
  firstEl -> _val = 0;
  _head = firstEl;

  MyNode *temp = firstEl;

  //utworz pozostale n - 1 elementow
  for(int i = 1; i < n; i++)
  {
    temp -> _ptrNext = new MyNode;
    temp = temp -> _ptrNext;
    temp -> _val = i;
  }
  temp -> _ptrNext = 0;
  _tail = temp;
}

// konstruktor z lista inicjalizacyjna
//  std::initializer_list<T>
MyList::MyList(std::initializer_list<int> l) 
{
  //cout << "KONST: std::initializer_list\n";
  printLineInColor("KONST: std::initializer_list\n");
  MyNode *temp = new MyNode;
  _head = temp;

  for (auto n : l)
  {
    //cout << "auto, n = " << n << /*"l = " << l <<*/ "\n";
    MyNode *newNode = new MyNode;
    temp -> _val = n;
    temp -> _ptrNext = newNode;
    _tail = temp; // uwaga na linijkę tę i poniżej, zamiana powodowała błędy
    temp = temp -> _ptrNext;
    _listSize++;
  }
}


//konstruktor kopiujacy
// (chyba) kopiuje &list do this
MyList::MyList(const MyList &list)
{
  printLineInColor("KONST: kopiujacy\n");
  // przepisz rozmiar
  _listSize = list._listSize;
  
  // tymczasowy wskaznik na starą liste
  MyNode *temp = list._head;
  // skopiuj wartości starej listy do tablicy
  int listValues[list._listSize];
  for (int i = 0; i < _listSize; i++)
  {
    //cout << "el : " << temp -> _val  << endl;
    listValues[i] = temp -> _val;
    temp = temp -> _ptrNext;
  }
  // utwórz tablicę i dodaj elementy 
  // za pomocą metody add
  //cout << "_listSize: " << _listSize << endl;
  for(int i = 0; i < list._listSize; i++)  
  { 
    this->add( listValues[i] );
    //this->print();
  }
}

//konstruktor przenoszacy
MyList::MyList(MyList &&list)
{
  printLineInColor("KONST: przenoszacy\n");
  
  //std::exchange(list, this);
  // wersja bez exchange

  // wystarczy przenieść wskaźniki
  _head = list._head;
  _tail = list._tail;
  _listSize = list._listSize;

  // stare należy wyzerować, bo destruktor nam zwariuje
  list._listSize = 0;
  list._head = list._tail = 0;


}

///////////////////////////////////////////////////////////////
// metody

void MyList::add(int n)
{
  //jesli lista jest pusta
  if(_tail == 0)
  {
    MyNode *newPtr = new MyNode;
    newPtr -> _val = n;
    _head = _tail = newPtr;
    _listSize = 1;
  }
  else
  {
    MyNode *newPtr = new MyNode;
    _tail -> _ptrNext = newPtr;
    _tail = newPtr;
    newPtr -> _val = n;
    _listSize++;
  }
}



// destruktor
MyList::~MyList()
{
  printLineInColor("DESTRUKTOR (rozmiar = ");
  cout  << _listSize << ")\n";
  this->clear();
}


// metody

bool MyList::empty() const
{ return _listSize == 0; }

int MyList::size() const
{ return _listSize; }

void MyList::print() const
{
  //jesli lista pusta to zakoncz
  if(_head == 0)
    {
      cout << "[]\n";
      return;
    }
  
  MyNode *temp = _head;
  cout << "[";
  while(temp != _tail)
  {
    cout << temp -> _val << ", ";
    temp = temp -> _ptrNext;
  }
  if (temp != 0)
    cout << temp -> _val << "]\n";


  
}

void MyList::clear()
{
  MyNode *temp = _head;
  //cout << "_tail: " << _tail << "\n";
  while(_head != _tail)
  {
    /*cout 
    << "head " << _head
    << "\ntemp " << temp
    << "\ntemp -> _ptrNext " << temp -> _ptrNext;*/
    _head = temp -> _ptrNext;
    delete temp;
    temp = _head;
    /*cout << "\n";*/
  }
  delete _tail;
  _tail = _head = 0;
  _listSize = 0;
}


///////////////////////////////////////////////////////////////
// MyNode

// konstruktor domyslny
/*MyNode::MyNode()
{
  cout << "KONST: Domyslny\n";
}
*/

int & MyNode::val()
{
  return _val;
}

