#include <iostream>
#include <algorithm>
#include "point2d.h"

Point2D::Point2D(){
    x = 0;
    y = 0;
}

Point2D::Point2D(float a, float b){
    x = a;
    y = b;
}

bool Point2D::operator ==(const Point2D& other){
    return x == other.x && y == other.y;
}
