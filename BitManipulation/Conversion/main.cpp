#include <iostream>

using namespace std;

int conversion(int a, int b) {
    int count = 0;
    for (int c = a ^ b; c != 0; c = c >> 1) {
        count += c & 1;
    }
    return count;
}

int conversion2(int a, int b) {
    int count = 0;
    for (int c = a ^ b; c != 0; c = c & (c-1)) {
        count++;
    }
    return count;
}

int main()
{
    int a = 29;
    int b = 15;
    cout << "Conversion: " << conversion(a, b) << endl;
    cout << "Conversion: " << conversion2(a, b) << endl;
    return 0;
}
