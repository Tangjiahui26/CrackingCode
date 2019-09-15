#include <iostream>

using namespace std;

// Given an array of postive numbers, find the maximum sum of a subsequence
// with the constraint that no 2 numbers in the sequence should be adjacent.

// simple solution
/*
 * maintain two sums:
 * incl - max sum including the previous element - excl + current element
 * excl - max sum excluding the previous element - max(incl, excl)
 */

int findMaxSum(int arr[], int n){
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;

    for (i = 1; i < n; i++){
        excl_new = (incl > excl) ? incl : excl;

        incl = excl + arr[i];
        excl = excl_new;
    }

    return ((incl > excl) ? incl : excl);
}

// DP solution
// either
// choose the current index: dp[i] = arr[i] + dp[i+2]
// or
// skip the current index: dp[i] = dp[i+1]
// so:
// dp[i] = max(dp[i+2]+arr[i], dp[i+1])

#define maxLen 10

int dp[maxLen];
//variable to check if a given state has been solved
bool v[maxLen];

int maxSum(int arr[], int i, int n){
    if (i >= n){
        return 0;
    }

    if(v[i]){
        return dp[i];
    }
    v[i] = 1;

    dp[i] = max(maxSum(arr, i+1, n), arr[i]+maxSum(arr, i+2, n));

    return dp[i];
}

int main()
{
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findMaxSum(arr, n) << endl;

    cout << maxSum(arr, 0, n) << endl;
    return 0;
}
