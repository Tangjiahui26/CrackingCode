#include <iostream>

using namespace std;

// The basic solution to this coding question is to
// count the pairs of multiples of 2 and 5

// since we can find that 2s are always more than or equal
// the number of 5s, so we can just calucate the number of 5s

// special cases: 25, 125

// approach 1: factorsOf5 + number iteration

int factorOf5(int i){
    int count = 0;
    while (i % 5 == 0){
        count++;
        i = i / 5;
    }
    return count;
}

int factorialZeros(int number){
    int count = 0;
    for (int i = 2; i <= number; i++){
        count += factorOf5(i);
    }
    return count;
}

// approach 2: just one iteration

int factorialZerosSimplification(int number){
    int count = 0;
    for (int i = 5; number / i >= 1; i *= 5){
        count += number / i;
    }
    return count;
}

int main()
{
    int test = 100;
    cout << "Result: " << factorialZeros(test) << endl;
    cout << "Result: " << factorialZerosSimplification(test) << endl;
    return 0;
}
