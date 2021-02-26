#include <iostream>
#include "DistanceOnMap.h"
#include "PointOnMap.h"
#include "PointOnMap.h"
#include "DistanceOnMap.h"

int main() {
  using std::cout;

  cout<<"========== KRK ==========\n";
  PointOnMap krk;
  krk.set_latitude(19.938333);
  krk.set_longitude(50.061389);
  krk.print();

  cout<<"========== NYC ==========\n";
  const double nyc_latitude = 40.7127;
  const double nyc_longitude = -74.0059;
  PointOnMap nyc;
  nyc.set_coordinates (nyc_latitude, nyc_longitude);
  nyc.print();

  cout<<"========== PORTO & IRKUTSK ==========\n";
  PointOnMap porto;
  porto.set_coordinates(41.162142, -8.621953);
  porto.print();
  PointOnMap irkutsk;
  irkutsk.set_coordinates(52.283333, 104.283333);
  irkutsk.print();

  cout<<"========== DISTANCE ==========\n";
	const PointOnMap portoCopy = porto;
  DistanceOnMap nyc_porto = nyc.distance(portoCopy);
  nyc_porto.print();

  cout<<"========== CLOSEST ==========\n";
  krk.closest(portoCopy, irkutsk).print();

  cout<<"========== SOMEWHERE ==========\n";
  krk.half_way_to(nyc).print();
  //krk.half_way_to(portoCopy).print();



  return 0;
}
/* Output:
========== KRK ==========
Point: (19.9383, 50.0614)
========== NYC ==========
Point: (40.7127, -74.0059)
========== PORTO & IRKUTSK ==========
Point: (41.1621, -8.62195)
Point: (52.2833, 104.283)
========== DISTANCE ==========
Distance: (0.449444, 65.3839)
========== CLOSEST ==========
Point: (41.1621, -8.62195)
========== SOMEWHERE ==========
Point: (30.3255, -11.9723)
*/