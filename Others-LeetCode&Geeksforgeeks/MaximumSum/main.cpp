#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Find elements which are present in first array and not in second

void findMissing(int a[], int b[], int n, int m){
    unordered_set<int> s;
    for (int i = 0; i < m; i++){
        s.insert(b[i]);
    }

    for (int i = 0; i < n; i++){
        if (s.find(a[i]) == s.end()){
            cout << a[i] << " ";
        }
    }
}

// Maximum sum combination from two arrays
/*
 * Given two arrays arr1[] and arr2[] each of
 * size N. The task is to choose some elements
 * from both the arrays such that no two elements
 * have the same index and no two consecutive
 * numbers can be selected from a single array.
 * Find the maximum sum possible of above-chosen
 * numbers.
 */

// Dynamic Programming
/*
 * dp(i, 1)=max(dp (i – 1, 2) + arr(i, 1), dp(i – 1, 3) + arr(i, 1), arr(i, 1) );
 * dp(i, 2)=max(dp(i – 1, 1) + arr(i, 2 ), dp(i – 1, 3) + arr (i, 2), arr(i, 2));
 * dp(i, 3)=max(dp(i- 1, 1), dp( i-1, 2) ).
 *
 * ==>
 *
 * dp(i, 1) = max(dp(i, 1), dp(i-1, 1))
 * dp(i, 2) = max(dp(i, 2), dp(i-1, 2)).
 *
 * max(dp(n, 1), dp(n, 2))
 */

int maxSum(int arr1[], int arr2[], int n){
    int dp[n][2];

    for (int i = 0; i < n; i++){

        //initialize
        if (i == 0){
            dp[i][0] = arr1[i];
            dp[i][1] = arr2[i];
            continue;
        }

        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + arr1[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + arr2[i]);
    }

    return max(dp[n-1][0], dp[n-1][1]);
}

int main()
{
    int a[] = { 1, 2, 6, 3, 4, 5 };
    int b[] = { 2, 4, 3, 1, 0 };
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[1]);
    findMissing(a, b, n, m);

    int arr1[] = {9, 3, 5, 7, 3};
    int arr2[] = {5, 8, 1, 4, 5};
    int n_s = sizeof(arr1) / sizeof(arr1[0]);
    // Function call
    cout << maxSum(arr1, arr2, n_s);
    return 0;
}
