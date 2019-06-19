#include <iostream>

using namespace std;

int pairwiseSwap(int n) {
    int num_odd = n & 0xaaaaaaaa;
    int logical_shifted = (int)((unsigned int) num_odd >> 1);

    int num_even = n & 0x55555555;
    int arithmetic_shifted = num_even << 1;

    return logical_shifted | arithmetic_shifted;
}

int main()
{
    // test1: 2730 : 101010101010
    // expected result: 1365 : 010101010101
    int test1 = 2730;
    cout << "Pairwise Swap: " << pairwiseSwap(test1) << endl;

    // test2: 240 : 11110000
    // expected result: 240 : 11110000
    int test2 = 240;
    cout << "Pairwise Swap: " << pairwiseSwap(test2) << endl;

    return 0;
}
