#include <iostream>

using namespace std;

int multiple_helper(int smaller, int bigger){
    if (smaller == 0){
        return 0;
    } else if (smaller == 1){
        return bigger;
    }

    int s = smaller >> 1;
    int half = multiple_helper(s, bigger);

    if (smaller % 2 == 0){
        return half + half;
    } else {
        return half + half + bigger;
    }
}

int multiple(int a, int b){
    int bigger = a < b ? b : a;
    int smaller = a < b ? a : b;
    return multiple_helper(smaller, bigger);
}

int main()
{
    int a = 9;
    int b = 11;
    cout << "Recursive Multiple: " << a << " * " << b << " = " << multiple(a, b) << endl;
    return 0;
}
