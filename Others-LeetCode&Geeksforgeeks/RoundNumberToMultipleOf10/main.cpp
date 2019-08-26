#include <iostream>
#include <string>

using namespace std;

// simple version:
// given a positive integer n, round it to nearest
// whole number having zero as last digit.

int round(int n){
    // smaller multiple
    int a = (n/10) * 10;
    // larger mutiple
    int b = a + 10;

    return (n - a > b - n) ? b : a;
}

// given a larger positive integer represented as
// a string str.

void roundToNearest(string str, int n){
    if(str == ""){
        return;
    }

    if (str[n - 1] - '0' <= 5){
        str[n - 1] = '0';
        cout << str.substr(0, n);
    } else {
        int carry = 0;
        str[n - 1] = '0';
        int i = n - 2;
        carry = 1;
        while (i >= 0 && carry == 1){
            int currentDigit = str[i] - '0';
            currentDigit += carry;

            if (currentDigit > 9){
                carry = 1;
                currentDigit = 0;
            } else {
                carry = 0;
            }

            str[i] = (char)(currentDigit + '0');
            i--;
        }
        if (carry == 1){
            cout << carry;
        }
        cout << str.substr(0, n);
    }
}

int main()
{
    int n = 4726;
    cout << round(n) << endl;
    string str = "999999999999999993";
    int s = str.size();
    roundToNearest(str, s);
    return 0;
}
