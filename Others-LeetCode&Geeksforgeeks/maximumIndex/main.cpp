#include <iostream>

using namespace std;

// Given an array arr[], find the maximum j - i such that arr[j] > arr[i]

//simple two loops solution - O(N^2)

int maximumIndex(int arr[], int n){
    int maxDiff = -1;
    int i, j;

    for (i = 0; i < n; ++i){
        // from back to front to get max
        for (j = n-1; j > i; --j){
            if (arr[j] > arr[i] && maxDiff < (j - i)){
                maxDiff = j - i;
            }
        }
    }

    return maxDiff;
}

// Optimal solution - Using two extra arrays - O(n) runtime
// LMin[i] holds the smallest element on left side of arr[i] including arr[i]
// Rmax[j] holds the greatest element on right side of arr[j] including arr[j]

int maxIndex(int arr[], int n){
    int maxDiff;
    int i, j;

    int *LMin = new int[(sizeof(int) * n)];
    int *RMax = new int[(sizeof(int) * n)];

    // construct LMin[]
    LMin[0] = arr[0];
    for (i = 1; i < n; ++i){
        LMin[i] = min(arr[i], LMin[i-1]);
    }

    // construct RMax[]
    RMax[n - 1] = arr[n-1];
    for (j = n-2; j>=0; --j){
        RMax[j] = max(arr[j], RMax[j+1]);
    }

    i = 0, j = 0, maxDiff = -1;
    while(j < n && i < n){
        if (LMin[i] < RMax[j]){
            maxDiff = max(maxDiff, j - i);
            j = j + 1;
        } else {
            i = i + 1;
        }
    }
    return maxDiff;
}

int main()
{
    int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    // expected 8
    cout << maximumIndex(arr, n) << endl;
    cout << maxIndex(arr, n) << endl;
    return 0;
}
