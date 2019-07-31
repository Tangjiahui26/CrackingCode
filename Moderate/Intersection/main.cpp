#include <iostream>
#include <utility>
#include <algorithm>
#include <cfloat>

using namespace std;

typedef pair<double, double> point;

point lineIntersection(point A, point B, point C, point D){
    // Line AB represented as a1x + b1y = c1
    double a1 = B.second - A.second;
    double b1 = A.first - B.first;
    double c1 = a1*(A.first) + b1*(A.second);

    // Line CD represented as a2x + b2y = c2
    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2*(C.first) + b2*(C.second);

    // calculate determinant = a1b2 - a2b1
    double d = a1*b2 - a2*b1;
    if (d == 0){
        return make_pair(FLT_MAX, FLT_MAX);
    } else {
        double x = (b2*c1 - b1*c2)/d;
        double y = (a1*c2 - a2*c1)/d;
        // if they are line segments, then we need to check if (x, y) on the segments
        return make_pair(x, y);
    }
}

void displayPoint(point p){
    cout << "(" << p.first << ", " << p.second << ")" << endl;
}

int main()
{
    point A = make_pair(1, 1);
    point B = make_pair(4, 4);
    point C = make_pair(1, 8);
    point D = make_pair(2, 4);

    point i = lineIntersection(A, B, C, D);
    if (i.first == FLT_MAX && i.second == FLT_MAX){
        cout << "Parallel" << endl;
    } else {
        // we thinks AB and CD are lines, so no check rightnow
        displayPoint(i);
    }
    return 0;
}
