#include "point2d.h"

class Rectangle
{
    // initial size of rectangle
    float width;
    float height;
    // coordinates
    Point2D topLeft;
    Point2D topRight;
    Point2D bottomLeft;
    Point2D bottomRight;
public:
    // constructor with initial size and coordinates
    Rectangle(float w, float h, float x, float y);
    Rectangle(Point2D& p1, Point2D& p2);

    // copy constructor
    Rectangle(const Rectangle& other);

    // assignment constructor
    Rectangle& operator=(const Rectangle& other);

    // checking methods
    bool checkPoint(Point2D& p);
    bool checkRectangle(Rectangle& other);

    // overloading
    bool operator ==(const Rectangle& other);

    // print info
    void printCoordinates();
};
