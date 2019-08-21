#include <iostream>

using namespace std;

//SubProblem: Draw a circle without floating point arithmetic
/*
 * Given a radius of a circle, draw the circle
 * without using floating point arithmetic.
 */

// Consider a square of size (2r+1)*(2r+1) around the circle to be drawn

void drawCircle(int r){
    int N = 2*r+1;

    int x, y;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            x = i - r;
            y = j - r;

            if (x*x + y*y <= r*r+1){
                printf(".");
            } else {
                printf(" ");
            }
            printf(" ");
        }
        printf("\n");
    }
}

// Mid-Point Circle Drawing Algorithm
/*
 * For any given pixel (x, y), the next pixel to be plotted is
 * either (x, y+1) or (x-1, y+1). This can be decided by following
 * the setps:
 * 1. Find the mid-point p of the two possible pixels i.e (x-0.5, y+!_
 * 2. If p lies inside or on the circle permiter, plot the pixel (x, y+1),
 *    Otherwise if it's outside, we plot the pixel (x-1, y+1).
 */

void midPointCircleDrawing(int x_centre, int y_centre, int r){
    int x =r, y =0;

    printf("(%d, %d) ", x + x_centre, y + y_centre);

    if (r > 0){
        printf("(%d, %d) ", x + x_centre, -y + y_centre);
        printf("(%d, %d) ", y + x_centre, x + y_centre);
        printf("(%d, %d) ", -y + x_centre, x + y_centre);
    }

    // P1 = (r-0.5)^2 + (0+1)^2 -r^2 = 1.25 -r = 1 -r (rounded off)
    int P = 1 - r;
    while (x > y){
        y++;

        if (P <= 0){
            P = P + 2*y +1;
        } else {
            x--;
            P = P + 2*y - 2*x + 1;
        }

        if (x < y){
            break;
        }

        printf("(%d, %d) ", x + x_centre, y + y_centre);
        printf("(%d, %d) ", -x + x_centre, y + y_centre);
        printf("(%d, %d) ", x + x_centre, -y + y_centre);
        printf("(%d, %d) ", -x + x_centre, -y + y_centre);

        if (x != y){
            printf("(%d, %d) ", y + x_centre, x + y_centre);
            printf("(%d, %d) ", -y + x_centre, x + y_centre);
            printf("(%d, %d) ", y + x_centre, -x + y_centre);
            printf("(%d, %d) ", -y + x_centre, -x + y_centre);
        }
    }
}

// Bresenham’s circle drawing algorithm
/*
 * At Any point (x,y), we have two options either to choose
 * the next pixel in the east i.e (x+1, y) or in the south
 * east i.e (x+1, y-1)
 *
 * The decision is made by using the parameter d as:
 * if d > 0, then (x+1, y-1) is to be chosen as the next pixel
 * as it will be colser to the arc.
 * else (x+1, y) is to be chosen as next pixel
 *
 * Now for each pixel, we will do the following operations:
 * 1. Set initial values of (xc, yc) and (x, y)
 * 2. Set decision parameter d to d = 3 – (2 * r).
 * 3. call drawCircle(int xc, int yc, int x, int y) function.
 * 4. Repeat steps 5 to 8 until x < = y
 * 5. Increment value of x.
 * 6. If d < 0, set d = d + (4*x) + 6
 * 7. Else, set d = d + 4 * (x – y) + 10 and decrement y by 1.
 * 8. call drawCircle(int xc, int yc, int x, int y) function
 *
 * Here is pseduocode (C):
 *
 * #include <stdio.h>
   #include <dos.h>
   #include <graphics.h>
 *
 * Assume we have drawCircle(int xc, int yx, int x, int y)
 *
 * void drawCircle(int xc, int yc, int x, int y)
    {
        putpixel(xc+x, yc+y, RED);
        putpixel(xc-x, yc+y, RED);
        putpixel(xc+x, yc-y, RED);
        putpixel(xc-x, yc-y, RED);
        putpixel(xc+y, yc+x, RED);
        putpixel(xc-y, yc+x, RED);
        putpixel(xc+y, yc-x, RED);
        putpixel(xc-y, yc-x, RED);
    }
 */

void circleBres(int xc, int yc, int r){
    int x = 0; y = r;
    int d = 3 -2 * r;
    // call drawCircle() here

    while (y >= x){
        x++;
        if (d > 0){
            y--;
            d = d + 4 * (x-y) +10;
        } else {
            d = d + 4*x + 6;
        }
        // call drawCircle() here again
    }
}

int main()
{
    drawCircle(8);
    cout << endl;
    cout << endl;
    midPointCircleDrawing(0, 0, 3);
    return 0;
}
