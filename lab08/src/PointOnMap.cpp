#include <iostream>
#include "../include/PointOnMap.h"
#include "../include/DistanceOnMap.h"
#include <cmath>

using std::cout;
using std::endl;

  void PointOnMap::print()
  {
    cout << "Point: (" << latitude << ", " << longitude << ")" << endl;
  }
  void PointOnMap::set_latitude(double lat)
  {
    latitude = lat;
  }
  void PointOnMap::set_longitude(double lo)
  {
    longitude = lo;
  }
  void PointOnMap::set_coordinates(const double lat, const double lo)
  {
    set_latitude(lat);
    set_longitude(lo);
  }


  DistanceOnMap PointOnMap::distance(const PointOnMap point)
  {
    DistanceOnMap output;

    output.latitude = point.latitude - latitude;
    output.longitude = point.longitude - longitude;

    return output;
  }


  PointOnMap PointOnMap::closest(const PointOnMap point1, const PointOnMap point2)
  {
    double lat1 = (latitude - point1.latitude);
    double long1 = longitude - point1.longitude;
    double R1 = sqrt(lat1*lat1 + long1*long1);

    double lat2 = (latitude - point2.latitude);
    double long2 = longitude - point2.longitude;
    double R2 = sqrt(lat2*lat2 + long2*long2);
/*
    if(R1 < R2)
      return  point1;
    else
      return point2;*/

    return (R1 < R2 ? point1 : point2);
  }

  PointOnMap PointOnMap::half_way_to(const PointOnMap point)
  {
    PointOnMap output;
    output.latitude = (latitude + point.latitude)/2;
    output.longitude = (longitude + point.longitude)/2;
    return output;
  }