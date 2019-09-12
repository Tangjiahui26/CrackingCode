#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

// problem: Missing 1 number - Given an array with all the numbers from 1 to N appearing exactly once
// except for one number is missing.
// Find the missing number in O(N) time and O(1) space.

// method 1 use sum formula

int findMissingNumber(int a[], int n){
    int total = (n+1)*(n+2)/2;
    for (int i = 0; i < n; i++){
        total -= a[i];
    }
    return total;
}

// method 1 without integer overflow

int findMissingNumberWithoutOverflow(int a[], int n){
    int i, total = 1;
    for (i = 2; i<= (n+1); i++){
        total +=i;
        total -= a[i-2];
    }
    return total;
}

// method 2 XOR

int findMissingNumberUsingXOR(int a[], int n){
    int x1 = a[0];
    int x2 = 1;

    for (int i = 1; i < n; i++){
        x1 = x1 ^ a[i];
    }

    for (int i = 2; i <= n + 1; i++){
        x2 = x2 ^ i;
    }

    return x1 ^ x2;
}

// What if there were two numbers missing?

// method1: get the average of 2 missing numbers
// One of the numbers will be less than or equal to avg while
// the other one will be strictly greater than avg.

// we can find the first missing number as:
// Sum of natural number from 1 to avg - the sum of array elements smaller than avg

int getSum(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

// The range is [1,n], input array's size is n-2
pair<int, int> findTwoMissingNumbers(int arr[], int n){
    // sum of 2 missing number
    int sum = (n*(n+1)) /2 - getSum(arr, n -2);

    int avg = sum /2;

    int sumSmallerHalf = 0,  sumGreaterHalf = 0;
    for (int i = 0; i < n - 2; i++){
        if (arr[i] <= avg){
            sumSmallerHalf += arr[i];
        } else {
            sumGreaterHalf += arr[i];
        }
    }

    int totalSmallerHalf = (avg*(avg+1)) / 2;
    int smallerElement = totalSmallerHalf - sumSmallerHalf;
    int greaterElement = sum - smallerElement;
    return make_pair(smallerElement, greaterElement);
}

int main()
{
    int arr[] = {1, 2, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findMissingNumber(arr, n) << endl;
    cout << findMissingNumberWithoutOverflow(arr, n) << endl;
    cout << findMissingNumberUsingXOR(arr, n) << endl;
    int arr1[] = {1, 2, 5, 6};
    int n1 = 2 + sizeof(arr1)/sizeof(arr1[0]);
    auto res = findTwoMissingNumbers(arr1, n1);
    cout << res.first <<  " " << res.second << endl;
    return 0;
}
