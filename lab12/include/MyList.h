#pragma once
#include <initializer_list>

/*
	KOMENTARZE:
	z niewiadomych przyczyn w outpucie prowadzącego
	przed każdym konstruktorem działa jeszcze konstruktor
	domyślny.

	TO DO
	- Konstruktor przenoszący 
	(użyć std::exchange)
	- Konstruktor: funkcja generującaa
		ostatni paragraf
*/

void printHeaderInColor(const char * line);
void printLineInColor(const char * line);
class MyList;

class MyNode{
  friend MyList;
private:
public:
  int _val;
  MyNode *_ptrNext;
public:
  int & val();
  //MyNode();
};

///////////////////////////////////////////////////////
class MyList{
private:
public:
int _listSize = 0;

MyNode *_head = 0;
MyNode *_tail = 0;

public:

//kontruktor domyslny
MyList();
// kontruktor jednoargumentowy
MyList(int n);
// konstruktor z lista inicjalizacyjna
MyList(std::initializer_list<int> l);
//konstruktor kopiujacy
MyList(const MyList &list);
//konstruktor przenoszacy
MyList(MyList &&list);


// destruktor
~MyList();

// metoda sprawdzajaca, czy lista jest pusta
bool empty() const;
// metoda zwracajaca rozmiar listy
int size() const;
// metoda wypisujaca zawartosc listy
void print() const;
//czyszczenie listy
void clear();
// dodawanie elementu na koniec listy
void add(int);

};




