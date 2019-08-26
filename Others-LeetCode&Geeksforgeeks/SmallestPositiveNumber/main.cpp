#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// Problem description: Find the smallest positive
// number missing from an unsorted arrary

// approach 1: create a list full of 0's with size of the max() value
// of the given array

int smallestPositiveNumber(int arr[], int n){
    int m = INT_MIN;
    for (int i = 0; i < n; i++){
        if (arr[i] > m){
            m = arr[i];
        }
    }

    if (m < 1){
        return 1;
    }
    if (n == 1){
        if (arr[0] == 1){
            return 2;
        } else {
            return 1;
        }
    }

    int i = 0;
    int l[m];
    // allocate the memory
    memset(l, 0, m*sizeof(int));
    for (i = 0; i < n; i++){
        if (arr[i] > 0){
            if (l[arr[i] - 1] != 1){
                l[arr[i] - 1] = 1;
            }
        }
    }

    for (i = 0; i < m; i++){
        if (l[i] == 0){
            return i + 1;
        }
    }
    // if all values are filled between 1 and m
    return i + 2;
}

// approach 2: using a set

int findsmallestPositiveNumber(int arr[], int n){
    // default smallest postive integer
    int m = 1;

    set<int> x;

    for (int i = 0; i < n; i++){
        if (m < arr[i]){
            x.insert(arr[i]);
        } else if (m == arr[i]){
            m = m + 1;

            while(x.count(m)){
                x.erase(m);
                m = m + 1;
            }
        }
    }
    return m;
}

int main()
{
    int test[] = {0, 1, 10, 2, 2, -1, -20};
    int s = sizeof(test)/sizeof(test[0]);
    cout << smallestPositiveNumber(test, s) << endl;;
    cout << findsmallestPositiveNumber(test, s) << endl;
    return 0;
}
