#include <iostream>
#include <chrono>

using namespace std;

// Here is the solution for a similar questions: find two rectangles overlap

class Point {
public:
  double x, y;
  Point(double x, double y) : x(x), y(y){}
  bool operator==(const Point& other) const {
      return x == other.x && y == other.y;
  }
};

class Line {
public:
    Point a, b;
    Line(Point a, Point b) : a(a), b(b){}
};

// l1: top left coordinate of first rectangle
// r1: bottom right coordinate of first rectangle
// l2: top left coordinate of second rectangle
// r2: bottom right coordinate of second rectangle
bool overlap(Point l1, Point r1, Point l2, Point r2){
    if (l1.x > r2.x || l2.x > r1.x)
        return false;
    if (l1.y < r2.y || l2.y < r1.y)
        return false;
    return true;
}

class Square {
public:
    double left;
    double top;
    double right;
    double bottom;
    Square(double left, double top, double size){
        this->left = left;
        this->top = top;
        this->right = left + size;
        this->bottom = top + size;
    }

    Point getMiddle(){
        return Point((this->left + this->right)/2, (this->top + this->bottom)/2);
    }

    Line cut(Square other){
        Point mid_s = this->getMiddle();
        Point mid_t = other.getMiddle();
        if (mid_s == mid_t){
            return Line(Point(left,top), Point(right, bottom));
        } else {
            return Line(mid_s, mid_t);
        }
    }
};



int main()
{
    Point l1 = {0, 10};
    Point r1 = {10, 0};
    Point l2 = {5, 5};
    Point r2 = {15, 0};
    if (overlap(l1, r1, l2, r2))
        printf("Overleap");
    else
        printf("Don't overleap");
    return 0;
}
