#pragma once
#include "DistanceOnMap.h"

class DistanceOnMap;

//klasa reprezentujaca punkt o wspolrzednych(dlugosc,szerokosc) na kuli ziemskiej
class PointOnMap
{
public:

  //wspolrzedne punktu (dlugosc, szerokosc)
  double longitude, latitude; 

  //metoda wyswietlajaca wspolrzedne punktu na ekranie
  void print(); 

  //metoda przypisujaca punktowi dlugosc typu double
  void set_latitude(double);

  //metoda przypisujaca punktowi szerokosc typu double
  void set_longitude(double);

  //metoda ustawiajaca punktowi wspolrzedne (dlugosc, szerokosc)
  void set_coordinates(const double, const double);

  //metoda obliczajaca odleglosc miedzy dwoma punktami
  //zwracajaca odlegosc ktora jest reprezentowana 
  //przez klase DistanceOnMap
  DistanceOnMap distance(const PointOnMap);

  //metoda closest przyjmuje dwa punkty
  //i wybiera blizszy z nich temu punktowi, 
  //na ktorym jest wywolana
  PointOnMap closest(const PointOnMap, const PointOnMap);

  //metoda zwracajaca punkt lezacy w polowie odleglosci
  //miedzy punktem, na ktorym jest wywolana
  //a punktem podanym jako argument metody
  PointOnMap half_way_to(const PointOnMap);

  
};