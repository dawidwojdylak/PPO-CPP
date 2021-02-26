#pragma once
#include <iostream>
#include <cmath>

class Vector2D
{
private:
  double _x; // wspolrzedna x wektora w ukladzie kartezjanskim
  double _y; // wspolrzedna y wektora w ukladzie kartezjanskim

  //konstruktor tworzacy wektor (wsp. x, wsp. y)
  Vector2D(double x, double y);

public:

  // zmienna liczaca, ile mamy obecnie utworzonych wektorow
  static int count;

  // metoda zwracajaca wektor przymujmaca argumenty
  // w ukladzie kartezjanskim (wsp. x, wsp. y)
  static Vector2D fromCarthesian(double x, double y);
  // metoda zwracajaca wektor przyjmujaca argumenty
  // w ukladzie biegunowym (promien, kat[rad])
  static Vector2D fromPolar(double r, double rad);

  // metoda wypisujaca wektor na ekran
  // przyjmuje nazwe wektora jako argument
  void print(const char * txt) const;
  // metoda zwracajaca iloczyn skalarny dwoch wektorow
  double dot(const Vector2D &vec) const;
  // metoda zwracajaca wektor, 
  // ktory jest suma dwoch wektorow (this + vec)
  Vector2D add(const Vector2D &vec) const;

  //kostruktor kopiujacy 
  Vector2D(const Vector2D &vec );
  //konstruktor przenoszacy
  Vector2D(const Vector2D &&vec);
  // destruktor
  ~Vector2D();

};

inline Vector2D Vector2D::fromCarthesian(double x, double y)
{
  Vector2D output = Vector2D(x,y);
  return output;
}

inline Vector2D Vector2D::fromPolar(double r, double rad)
{
  double alpha = rad * M_PI / 180;
  Vector2D output = Vector2D(r * cos(alpha) , r * sin(alpha));
  return output;
}