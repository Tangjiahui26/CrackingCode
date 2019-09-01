#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// problem: given two strings str1 and str2 and Find minimum number of edits (operations)
// required to converst str1 into str2

// 1. insert 2. remove 3. replace

// recursively solution - O(3^m)
// if last characters of two strings are same, nothing much to do. recur for lengths m-1 and n-1
// else we consider all operations on 'str1': insert, remive and replace

int editDist(string str1, string str2, int m, int n){
    if (m == 0) return n;
    if (n == 0) return m;

    if (str1[m-1] == str2[n-1]){
        return editDist(str1, str2, m-1, n-1);
    }

    return 1 + min(min(editDist(str1, str2, m, n-1), //insert
                       editDist(str1, str2, m-1, n)), // remove
                   editDist(str1, str2, m-1, n-1)); // replace
}

// dynamic programming

int editDistDP(string str1, string str2, int m, int n){
    int dp[m+1][n+1];

    // bottom-up
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            if (i == 0){
                dp[i][j] = j;
            } else if (j == 0){
                dp[i][j] = i;
            } else if (str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDist(str1, str2, str1.length(), str2.length()) << endl;
    cout << editDistDP(str1, str2, str1.length(), str2.length()) << endl;
    return 0;
}
