#include <iostream>
#include <cmath>

using namespace std;


// brute force
int countOf2s(int n){
    int counts = 0;
    while(n > 0){
        if (n % 10 == 2){
            counts++;
        }
        n =  n / 10;
    }
    return counts;
}

int getCounts(int n){
    int counts = 0;
    for (int i = 2; i <= n; i++){
        counts += countOf2s(i);
    }

    return counts;
}

// look at the problem digit by digit

int count2sInRangeAtDigit(int number, int d){
    int powerOf10 = pow(10, d);
    int nextPowerOf10 = powerOf10 * 10;
    int right = number % powerOf10;

    int roundDown = number - number % nextPowerOf10;
    int roundUp = roundDown + nextPowerOf10;

    int digit = (number / powerOf10) % 10;
    if (digit < 2){
        // case d < 2
        // let y = round down to nearest 10^(d+1), return y/10;
        return roundDown / 10;
    } else if (digit == 2){
        // case d == 2
        //let y = round down to nearest 10^(d+1), z = right size of x, then return y /10 + z + 1
        return roundDown / 10 + right + 1;
    } else {
        // case d > 2
        return roundUp / 10;
    }
}

int getCountsDigitByDigit(int n){
    int counts = 0;
    int len = static_cast<int>(to_string(n).size());
    for (int digit = 0; digit < len; digit++){
        counts += count2sInRangeAtDigit(n, digit);
    }
    return counts;
}

int main()
{
    cout << getCounts(23087) << endl;
    cout << getCountsDigitByDigit(23087) << endl;
    return 0;
}
