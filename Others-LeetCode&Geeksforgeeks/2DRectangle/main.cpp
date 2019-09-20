#include <iostream>
#include <algorithm>
#include <cmath>
#include "2drectangle.h"

using namespace std;

// consturctor using given sizes and bottom left point
Rectangle::Rectangle(float w, float h, float x, float y){
    width = w;
    height = h;
    bottomLeft = Point2D(x, y);
    bottomRight = Point2D(x+w, y);
    topLeft = Point2D(x, y+h);
    topRight = Point2D(x+w, y+h);
}

// constructor using two points
Rectangle::Rectangle(Point2D &p1, Point2D &p2){
    width = abs(p1.getX() - p2.getX());
    height = abs(p1.getY() - p2.getY());

    if (p1.getX() <= p2.getX()){
        if (p1.getY() <=  p2.getY()){
            bottomLeft = p1;
            topRight = p2;
            bottomRight = Point2D(topRight.getX(), bottomLeft.getY());
            topLeft = Point2D(bottomLeft.getX(), topRight.getY());
        } else {
            topLeft = p1;
            bottomRight = p2;
            bottomLeft = Point2D(topLeft.getX(), bottomRight.getY());
            topRight = Point2D(bottomRight.getX(), topLeft.getY());
        }
    } else {
        if (p1.getY() <= p2.getY()){
            bottomRight = p1;
            topLeft = p2;
            bottomLeft = Point2D(topLeft.getX(), bottomRight.getY());
            topRight = Point2D(bottomRight.getX(), topLeft.getY());
        } else {
            topRight = p1;
            bottomLeft = p2;
            bottomRight = Point2D(topRight.getX(), bottomLeft.getY());
            topLeft = Point2D(bottomLeft.getX(), topRight.getY());
        }
    }
}

Rectangle::Rectangle(const Rectangle &other){
    width = other.width;
    height = other.height;
    bottomLeft = other.bottomLeft;
    bottomRight = other.bottomRight;
    topLeft = other.topLeft;
    topRight = other.topRight;
}

Rectangle& Rectangle::operator =(const Rectangle& other){
    if (this==&other){
        width = other.width;
        height = other.height;
        bottomLeft = other.bottomLeft;
        bottomRight = other.bottomRight;
        topLeft = other.topLeft;
        topRight = other.topRight;
    }
    return *this;
}

bool Rectangle::operator ==(const Rectangle& other){
    return width == other.width && height == other.height
            && bottomLeft == other.bottomLeft && bottomRight == other.bottomRight
            && topLeft == other.topLeft && topRight == other.topRight;
}

// algorithm that checks if or not a 2D point is contained in an anis-aligned Rectangle
bool Rectangle::checkPoint(Point2D &p){
    if ((bottomLeft.getX() <= p.getX()
         && bottomRight.getX() >= p.getX())
            && (bottomLeft.getY() <= p.getY()
                && topLeft.getY() >= p.getY())) {
        return true;
    } else {
        return false;
    }
}

// algorithm that checks whether or not two axis-aligned Rectangles intersect
bool Rectangle::checkRectangle(Rectangle &other){
    if (checkPoint(other.bottomLeft) || checkPoint(other.bottomRight)
            || checkPoint(other.topLeft) || checkPoint(other.topRight)
            || other.checkPoint(this->bottomLeft) || other.checkPoint(this->bottomRight)
            || other.checkPoint(this->topLeft) || other.checkPoint(this->topRight)) {
        return true;
    } else {
        return false;
    }
}

void Rectangle::printCoordinates(){
    // print coordinates topLeft, topRight, bottomRight, and bottomLeft
    cout << "(" << topLeft.getX()  << ", " << topLeft.getY() << "), ("
         << topRight.getX() << ", " << topRight.getY() << "), ("
         << bottomRight.getX() << ", " << bottomRight.getY() << "), ("
         << bottomLeft.getX() << ", " << bottomLeft.getY() << ")" << endl;
}

int main()
{
    // here is simple test code that creates instances of Rectangle class and tests the implementation

    // Test case 1:
    cout << "\t===test case 1===\t" << endl;
    cout << "Constructor with inital size and bottomLeft Point." << endl;
    Rectangle rt1 = Rectangle(2.5, 3, 1.5, 2.5);
    cout << "Expected Results: (1.5, 5.5), (4, 5.5), (4, 2.5), (1.5, 2.5)" << endl;
    cout << "rt1 Results:      ";
    rt1.printCoordinates();

    // Test case 2:
    cout << "\t===test case 2===\t" << endl;
    cout << "CheckPoint Algorithm" << endl;
    Point2D p1 = Point2D(2, 3);
    Point2D p2 = Point2D(4, 5.5);
    Point2D p3 = Point2D(5, 5);
    Point2D p4 = Point2D(6, 6);

    cout << "Point 1 (2, 3) is contained in rect1?" << endl;
    cout << "Expected Result: Yes" << endl;
    string res1 = rt1.checkPoint(p1) ? "Yes" : "No";
    cout << "Result: " << res1 << endl;

    cout << "Point 2 (4, 5.5) is contained in rect1?" << endl;
    cout << "Expected Result: Yes" << endl;
    string res2 = rt1.checkPoint(p2) ? "Yes" : "No";
    cout << "Result: " << res2 << endl;

    cout << "Point 3 (5, 5) is contained in rect1?" << endl;
    cout << "Expected Result: No" << endl;
    string res3 = rt1.checkPoint(p3) ? "Yes" : "No";
    cout << "Result: " << res3 << endl;

    cout << "Point 4 (6, 6) is contained in rect1?" << endl;
    cout << "Expected Result: No" << endl;
    string res4 = rt1.checkPoint(p4) ? "Yes" : "No";
    cout << "Result: " << res4 << endl;

    // Test case 3:
    cout << "\t===test case 3===\t" << endl;
    cout << "Constructor with two points" << endl;
    Rectangle rt2 = Rectangle(p1, p2);
    Rectangle rt3 = Rectangle(p1, p3);
    Rectangle rt4 = Rectangle(p2, p3);
    Rectangle rt5 = Rectangle(p3, p4);

    cout << "Rect 2 Expected Results: (2, 5.5), (4, 5.5), (4, 3), (2, 3)" << endl;
    cout << "Rect 2 Results:          ";
    rt2.printCoordinates();
    cout << endl;

    cout << "Rect 3 Expected Results: (2, 5), (5, 5), (5, 3), (2, 3)" << endl;
    cout << "Rect 3 Results:          ";
    rt3.printCoordinates();
    cout <<endl;

    cout << "Rect 4 Expected Results: (4, 5.5), (5, 5.5), (5, 5), (4, 5)" << endl;
    cout << "Rect 4 Results:          ";
    rt4.printCoordinates();
    cout << endl;

    cout << "Rect 5 Expected Results: (5, 6), (6, 6), (6, 5), (5, 5)" << endl;
    cout << "Rect 5 Results:          ";
    rt5.printCoordinates();
    cout << endl;

    // Test case 4:
    cout << "\t===test case 4===\t" << endl;
    cout << "CheckRectangle Algorithm" << endl;

    cout << "rect 1 is intersected with rect 2?" << endl;
    cout << "Expected result: Yes" << endl;
    string res5 = rt1.checkRectangle(rt2) ? "Yes" : "No";
    cout << "Result: " << res5 << endl;

    cout << "rect 1 is intersected with rect 3?" << endl;
    cout << "Expected result: Yes" << endl;
    string res6 = rt1.checkRectangle(rt3) ? "Yes" : "No";
    cout << "Result: " << res6 << endl;

    cout << "rect 1 is intersected with rect 4?" << endl;
    cout << "Expected result: Yes" << endl;
    string res7 = rt1.checkRectangle(rt4) ? "Yes" : "No";
    cout << "Result: " << res7 << endl;

    cout << "rect 1 is intersected with rect 5?" << endl;
    cout << "Expected result: No" << endl;
    string res8 = rt1.checkRectangle(rt5) ? "Yes" : "No";
    cout << "Result: " << res8 << endl;

    // test case 5:
    cout << "\t===test case 5===\t" << endl;
    cout << "Copy Constructor" << endl;
    Rectangle rt6(rt1);
    cout << "Rect 6 Expected Results: (1.5, 5.5), (4, 5.5), (4, 2.5), (1.5, 2.5)" << endl;
    cout << "Rect 6 Results:          ";
    rt6.printCoordinates();
    cout << endl;

    // test case 6
    cout << "\t===test case 6===\t" << endl;
    cout << "Assignment Constructor" << endl;
    Rectangle rt7 = rt2;
    cout << "Rect 7 Expected Results: (2, 5.5), (4, 5.5), (4, 3), (2, 3)" << endl;
    cout << "Rect 7 Results:          ";
    rt7.printCoordinates();
    cout << endl;

    return 0;
}
