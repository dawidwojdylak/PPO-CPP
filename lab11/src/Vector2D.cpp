#include <iostream>
#include "Vector2D.h"

using std::cout;

int Vector2D::count = 0;

  void Vector2D::print(const char * txt) const
  {
    cout << txt << "(" << _x << ", " << _y << ")\n";
  }

  double Vector2D::dot(const Vector2D &vec) const
  {
    double output;
    output = _x * vec._x + _y * vec._y;
    return output;
  }

  Vector2D Vector2D::add(const Vector2D &vec) const
  {
    Vector2D output = Vector2D( _x + vec._x , _y + vec._y );
    return output;
  }


  Vector2D::Vector2D(double x, double y)
  :
  _x(x),
  _y(y)
  {
    count++;
  }

  Vector2D::Vector2D(const Vector2D &vec) 
  :
  _x(vec._x),
  _y(vec._y)
  {
    cout <<  "copying ";
    print("");
    count++;
  }

  Vector2D::Vector2D(const Vector2D &&vec)
  :
  _x(std::move(vec._x)),
  _y(std::move(vec._y))
  {
    cout << "moving ";
    print("");
    count++;
  }

  Vector2D::~Vector2D()
  {
    count--;
  }
  