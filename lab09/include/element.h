#pragma once
#include "studList.h"

class StudList;

class Element
{
  friend StudList;
public:
  Element(const char *data);
  ~Element();
  const char * getName() const;
  void printName();

private:
  const char * _data;
  Element *_ptrNext;
};
