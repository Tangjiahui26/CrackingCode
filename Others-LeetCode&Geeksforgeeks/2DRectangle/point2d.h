class Point2D
{
    float x;
    float y;

public:
    Point2D();
    Point2D(float a, float b);
    float getX() {return x;}
    float getY() {return y;}

    // overloading
    bool operator==(const Point2D& other);
};
