#include <iostream>

using namespace std;

void swappingByDiff(int &a, int &b){
    // we assume that a is greater than b
    a = a - b; // diff
    b = a + b;
    a = b - a;
}

// more general, we can use XOR to swap two data

template<class T>
void swappingXOR(T &a, T &b){
    a = a^b;
    b = a^b; // 1 -> flips ; 0 -> keeps the same
    a = a^b;
}
int main()
{
    int test_a = 10;
    int test_b = 5;
    swappingByDiff(test_a, test_b);
    cout << "After Swapping: a is "<< test_a << ", b is " << test_b << endl;

    long a = 133;
    long b = 2;
    swappingXOR<long>(a, b);
    cout << "After Swapping: a is "<< a << ", b is " << b << endl;
    return 0;
}
