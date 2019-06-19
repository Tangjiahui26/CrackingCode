#include <iostream>

using namespace std;

// Get the bigger number
int getNext(int n){
    // get the c0 and c1
    int c = n;
    int c0 = 0;
    int c1 = 0;

    while(((c & 1) == 0) && (c != 0)){
        c0++;
        c >>= 1;
    }

    while((c & 1) == 1) {
        c1++;
        c >>= 1;
    }

    if (c0 + c1 == 31 || c0 + c1 == 0) {
        return -1;
    }

    int p = c0 + c1;

    // flip the rightmost non-trailing zero
    n |= (1 << p);

    // clear all bits to the right of p
    n &= ~((1 << p) - 1);

    // Insert (c1-1) ones on the right
    n |= (1 << (c1 - 1)) - 1;

    return n;

    // Arithmetic approach
//    return n + (1 << c0) + (1 << (c1 - 1)) - 1;
}

int getPrev(int n) {
    int temp = n;
    int c0 = 0;
    int c1 = 0;

    while((temp & 1) == 1) {
        c1++;
        temp >>= 1;
    }

    if (temp == 0) {
        return -1;
    }

    while(((temp & 1)) == 0 && (temp != 0)){
        c0++;
        temp >>= 1;
    }

    int p = c0 + c1;

    // clears from bit p onwards
    n &= ((~0) << (p+1));

    // sequence of (c1+1) ones
    int mask = (1 << (c1 + 1)) - 1;

    n |= mask << (c0 -1);
    return n;

    // Arithmetic approach
    // return n - (1 << c1) - (1 << (c0 -1)) + 1;
}

int main()
{
    // test1 = 13948 : 11011001111100
    // expected next bigger number is 13967 : 11011010001111
    int test1 = 13948;
    cout << "Next bigger number of 13948 is " << getNext(test1) << endl;
    cout << "The smaller number of 13948 is " << getPrev(test1) << endl;

    // test2 = 10115 : 10011110000011
    //expected the smaller number is 10096 : 10011101110000
    int test2 = 10115;
    cout << "Next bigger number of 10115 is " << getNext(test2) << endl;
    cout << "The smaller number of 10115 is " << getPrev(test2) << endl;
    return 0;
}
