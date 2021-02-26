#include "studList.h"
#include "element.h"
#include <iostream>
//do usuniecia 
#include "../include/studList.h"

using std::cout;
using std::endl;

/////////////////////////////////////////////////////////

  
  StudList::StudList(const char* listName )
  {
    _nameOfThisList = listName;
    _head = 0;
    _tail = 0;
  }
  
  StudList::~StudList()
  {
    cout << "Destruktor StudList: " << _nameOfThisList << endl;
    delete [] _nameOfThisList;
  }
  
  void StudList::prepend(const char* elData )
  {
    Element *newEl = new Element(elData);
    prepend(newEl);
  }
  
  /*void StudList::prepend(Element &el)
  {
    cout << "prepeneddsdsf" << endl;
       if(!_head){
              _head = &el;
              cout << "prep Head!!" << endl;
           }
      if(!_tail)
      {
        cout << "_tailll !\n";
        _tail = &el;
        return;
      }

      el._ptrNext = _head;
      _head = &el;
  }*/
  void StudList::prepend(Element *el)
  {
    //cout << "prepeneddsdsf" << endl;
    if(!_head){
         _head = el;
     //    cout << "prep Head!!" << endl;
       }
    if(!_tail)
    {
     // cout << "_tailll !\n";
      _tail = el;
      return;
    }
      el -> _ptrNext = _head;
      _head = el;
  }
  
  Element *StudList::getHead()
  {
    return _head;
  }
  
  Element *StudList::getTail()
  {
    return _tail;
  }
  
  bool StudList::isEmpty() const
  {
    return _head == 0;
  }

  void StudList::print() const
  {
    if (!_head) return;
    Element *temp = _head;
    cout << _nameOfThisList << " = [";
    while (temp != _tail)
    {
      cout << temp -> _data << " ";
      temp = temp -> _ptrNext;
    }
    cout << temp -> _data << "]" << endl;
  }

  

  Element* StudList::getLast()
  {
    Element *memory = _tail;
    Element *temp = _head;
    while(temp /*-> _ptrNext*/ != _tail)
      temp = temp -> _ptrNext;
    _tail = temp;
    return memory;
  }

  void StudList::clearList()
  {
    if(_head) return;
    Element *temp = _head;
    if(_head)
    {
      while(temp -> _ptrNext)
      {
        _head = _head -> _ptrNext;
        delete temp;
        temp = _head;
      }
      delete _tail;
      _head = _tail = 0;
    }
  }
  
  const char* StudList::getName() const
  {
    return _nameOfThisList;
  }

  void StudList::removeLast()
  {
    Element *memory = _tail;
    Element *temp = _head;
    while(temp /*-> _ptrNext*/ != _tail)
      temp = temp -> _ptrNext;
    _tail = temp;
    delete memory;
  }

