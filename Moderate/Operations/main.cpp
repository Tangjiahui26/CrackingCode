#include <iostream>
#include <string>

using namespace std;

// negate()
int negateNum(int num){
    int neg = 0;
    int sig = num < 0 ? 1 : -1;

    while(num){
        neg += sig;
        num += sig;
    }
    return neg;
}

// minus : a + (-1)*b
int minusNum(int a, int b){
    return a + negateNum(b);
}

// abs()
int absNum(int num){
    if (num < 0){
        return negateNum(num);
    } else {
        return num;
    }
}

// multiplication
int multiplyNum(int a , int b){
    if (a < b){
        return multiplyNum(b, a);
    }

    int sum = 0;
    for (int i = absNum(b); i > 0; i = minusNum(i, 1)){
        sum +=a;
    }

    if (b < 0){
        sum = negateNum(sum);
    }
    return sum;
}

// division

int divideNum(int a, int b){
    if (b == 0){
       throw "Division by zero condition!";
    }
    int aabs = absNum(a);
    int babs = absNum(b);

    int product = 0;
    int x = 0;
    while (product + babs < aabs){
        product += babs;
        x++;
    }

    if ((a < 0 && b < 0) || (a > 0 && b > 0)){
        return x;
    } else {
        return negateNum(x);
    }
}

int main()
{
    cout << minusNum(99, -9) << endl;
    cout << multiplyNum(999, -2) << endl;
    cout << divideNum(-999, -2) << endl;
    return 0;
}
