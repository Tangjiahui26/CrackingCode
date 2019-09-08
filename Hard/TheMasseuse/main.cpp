#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Method 1: recursive - O(2^n)

int masseuseRecursiveUtil(int arr[], int index, int size){
    if (index >= size){
        return 0;
    }

    int bestWith = arr[index] + masseuseRecursiveUtil(arr, index + 2, size);

    int bestWithout = masseuseRecursiveUtil(arr, index + 1, size);

    return max(bestWith, bestWithout);
}

int masseuseRecursive(int arr[], int size){
    return masseuseRecursiveUtil(arr, 0, size);
}

// Method 2: recursive + memoization O(n) + O(n) space

int masseuseRecursiveMemoUtil(int arr[], int index, int size, vector<int>& memo){
    if (index >= size){
        return 0;
    }

    if (memo.at(index) == 0) {
        int bestWith = arr[index] + masseuseRecursiveMemoUtil(arr, index + 2, size, memo);

        int bestWithout = masseuseRecursiveMemoUtil(arr, index + 1, size, memo);

        memo[index] = max(bestWith, bestWithout);
    }

    return memo[index];
}

int masseuseRecursiveMemo(int arr[], int size){
    vector<int> memo(size, 0);
    return masseuseRecursiveMemoUtil(arr, 0, size, memo);
}

// Method 3: iteration + Optimal Space O(n) + O(1) space
// If we take r0, then we will definitely skip r1 and definitely take either r2 or r3.

int maxMinutes(int arr[], int size){
    int oneAway = 0;
    int twoAway = 0;

    for (int i = size - 1; i >= 0; i--){
        int bestWith = arr[i] + twoAway;
        int bestWithout = oneAway;

        int current = max(bestWith, bestWithout);
        twoAway = oneAway;
        oneAway = current;
    }
    return oneAway;
}

int main()
{
    int arr[] = {30, 15, 60, 75, 45, 15, 15, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << masseuseRecursive(arr, size) << endl;
    cout << masseuseRecursiveMemo(arr, size) << endl;
    cout << maxMinutes(arr, size) << endl;
    return 0;
}
