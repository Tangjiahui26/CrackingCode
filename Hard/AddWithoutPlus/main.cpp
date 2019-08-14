#include <iostream>

using namespace std;

// recursively

int addWithoutPlus(int a, int b){
    if (b == 0){
        return a;
    }
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return addWithoutPlus(sum, carry);
}

// iteratively

int addWithoutPlusInteratively(int a, int b){
    while (b != 0) {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return a;
}

int main()
{
    int test1 = 10;
    int test2 = 12;
    cout << "Sum of " << test1 << " and " << test2 << " is " << addWithoutPlus(test1, test2) << endl;
    cout << "Sum of " << test1 << " and " << test2 << " is " << addWithoutPlusInteratively(test1, test2) << endl;
    return 0;
}
