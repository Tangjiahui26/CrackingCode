#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

// brute force

int tripleStep(int n){
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else {
        return tripleStep(n-1) + tripleStep(n-2) + tripleStep(n-3);
    }
}

// memoization

int tripleStep_memo_helper(int n, int* memo){
    if (n < 0){
        return 0;
    } else if (n == 0){
        return 1;
    } else if (memo[n] > -1){
        return memo[n];
    } else {
        memo[n] = tripleStep_memo_helper(n - 1, memo) +
                  tripleStep_memo_helper(n - 2, memo) +
                  tripleStep_memo_helper(n - 3, memo);
        return memo[n];
    }
}

int tripleStep_memo(int n){
    const int anInt = sizeof(anInt);
    int memo[n + 1];
    std::fill(memo, memo+sizeof(memo)/anInt, -1);
    return tripleStep_memo_helper(n, memo);
}

int main()
{
    int test = 10;
    cout << "Triple step Solution: " << tripleStep(test) << endl;
    cout << "Triple step Solution: " << tripleStep_memo(test) << endl;
    return 0;
}
