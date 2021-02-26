#pragma once
#include <string>
#include <iostream>

//struktura przechowujaca wskaznik do pierwszego elementu listy jednokierunkowej struct node
typedef struct list{
  struct node *head = 0;
}OneWayList;

//lista jednokierunkowa przechowujaca dane typu string
struct node{
  struct node *next = 0;
  std::string data;
};

//procedura rozpoczynajaca liste jednokierunkowa zlozona z dwoch struktur node i list (OneWayList)
void prepare(OneWayList *arg);

//procedura dodajaca element typu string do listy
void add(OneWayList *arg, std::string text);

//procedura wypisujaca elementy listy OneWayList
void dump(const OneWayList *arg);

//procedura usuwajaca liste OneWayList i zwalniajaca pamiec
void clear(OneWayList *arg);

//nie mam pojecia, co ma zwracac ta funkcja 
int empty(const OneWayList *arg);