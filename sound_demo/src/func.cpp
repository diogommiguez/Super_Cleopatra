//
//  func.cpp
//  sound_demo
//
//  Created by Diogo Miguez on 27/06/2021.
//

#include "func.hpp"
#include "ofMath.h"

double distance(double x1, double y1, double x2, double y2)
{
    return pow(pow(x1 - x2, 2) + pow(y1 - y2, 2),1/2.0);
}
