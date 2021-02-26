#include "studList.h"
#include "element.h"
#include <iostream>
//do usuniecia 
#include "../include/studList.h"
#include "../include/element.h"

using std::cout;
using std::endl;

class StudList;

Element::Element(const char *data)
{
  _data = data;
}
Element::~Element()
{
  cout << "Destruktor Element: kasowanie " << _data << endl;
  delete [] _data;
}
const char * Element::getName() const
{
  return _data;
}
void Element::printName()
{
  cout << _data << endl;
}
