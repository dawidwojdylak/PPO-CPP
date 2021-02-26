#pragma once
#include "element.h"
#include "../include/element.h"

class Element;



//klasa obslugujaca liste typu class Element
class StudList
{
  friend Element;
public:
  //konstruktor tworzacy liste. Jego argumentem jest nazwa li
  StudList(const char* listName);
  //destruktor, zwalnia pamiec
  ~StudList();
  //metoda dodajaca element na poczatek listy
  //jej argumentem jest zawartosc listy _data
  void prepend(const char* elData);
  //metoda dodajaca gotowy element na poczatek listy
  void prepend(Element * el);
  ////metoda dodajaca gotowy element na poczatek listy poprzez referecje
  //void prepend(Element &el);
  //getter zwracajacy wskaznik na pierwszy element listy
  Element *getHead();
  //getter zwracajacy wskaznik na ostatni element listy
  Element *getTail();
  //metoda sprawdzajaca, czy lista jest pusta (true - jest pusta)
  bool isEmpty() const; 
  //metoda wypisujaca na ekran cala liste
  void print() const;
  // metoda usuwajaca element z listy
  // nie zwalnia jednak elementu, tylko go zwraca
  Element* getLast();
  // metoda zwalniajaca pamiec - usuwa liste
  void clearList();
  // metoda zwracajaca nazwe listy
  const char* getName() const;
  //metoda usuwajaca ostatni element listy i zwalniajaca pamiec
  void removeLast();


private:
  //wsk na pierwszy el listy
  Element* _head;
  //wsk na ostatni el listy
  Element* _tail;
  //nazwa listy
  const char * _nameOfThisList;
};

/*
//klasa reprezentujaca element listy typu class StudList
class Element
{
  friend StudList;
public:
  //konstruktor zapisujacy wartosc elementu
  Element(const char *data);
  //destruktor zwalniajacy pamiec
  ~Element();
  //metoda zwracajaca zawartosc elementu
  const char * getName() const;
  //metoda wypisujaca zawartosc elementu
  void printName();

private:
  // zawartosc elementu
  const char * _data;
  //wskaznik na nastepny element
  Element *_ptrNext;
};*/