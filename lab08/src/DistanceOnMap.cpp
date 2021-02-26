#include <iostream>
#include "../include/PointOnMap.h"
#include "../include/DistanceOnMap.h"

using std::cout;
using std::endl;

 void DistanceOnMap::print()
  {
    cout << "Distance: (" << latitude << ", " << longitude << ")" << endl;
  }