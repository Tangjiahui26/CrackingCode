#include <iostream>
#include <algorithm>

using namespace std;

// approach 1: using abs

int maxOfTwo(int a, int b){
    return 0.5 * (abs(a + b) + abs (a - b));
}

// approach 2: using bitwise

int maxOFTwoUsingBitwise(int x, int y){
    // we assume that a and b are all int
    // so shift should be sizeof(int) * CHAR_BIT - 1, which is 32 - 1 = 31

    // remember it is right shift
    return x - ((x - y) & (x - y) >> 31);
}

// follow-ups:

int minOFTwoUsingBitwise(int x, int y){
    // we assume that a and b are all int
    // so shift should be sizeof(int) * CHAR_BIT - 1, which is 32 - 1 = 31

    // remember it is right shift
    return y + ((x - y) & (x - y) >> 31);
}

int minOfThree(int x, int y, int z){
    // suppose all positive;
    int c = 0;
    while (x && y && z){
        x--;
        y--;
        z--;
        c++;
    }
    return c;
}

int main()
{
    int test_a = 13;
    int test_b = 879;
    int test_c = 65;
    cout << "Result: " << maxOfTwo(test_a, test_b) << endl;
    cout << "Result: " << maxOFTwoUsingBitwise(test_a, test_b) << endl;
    cout << "Result: " << minOFTwoUsingBitwise(test_a, test_b) << endl;
    cout << "Result: " << minOfThree(test_a, test_b, test_c) << endl;
    return 0;
}
