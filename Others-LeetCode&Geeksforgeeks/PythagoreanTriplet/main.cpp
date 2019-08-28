#include <iostream>
#include <cmath>

using namespace std;

// Given an array of integers, write a function that
// returns true if there is a triplet (a, b, c) that
// satisfies a^2 + b^2 = c^2


// Approach 1: Naive - iterate the array three times O(n^3)

// Approach 2: Using Sorting O(n^2)
// after sorting the squared array, fix 'c' as last element of sorted array
// now search for pair(b, c) in subarray between first element and 'c'
// until meet in middle
// If no pair found for current 'c', then move 'c' one position
// back and repeat previous step

bool isTriplet(int arr[], int n){
    for (int i = 0; i < n; i++){
        arr[i] = arr[i] * arr[i];
    }

    sort(arr, arr + n);

    for (int i = n - 1; i >= 2; i--){
        int l = 0;
        int r = i - 1;
        while (l < r){
            if (arr[l] + arr[r] == arr[i]){
                return true;
            }

            (arr[l] + arr[r] < arr[i]) ? l++ : r--;
        }
    }
    return false;
}

// Approach 3: Using Hashing O(max * max)

bool checkTriplet(int arr[], int n){
    int maximum = 0;
    for (int i = 0; i < n; i++){
        maximum = max(maximum, arr[i]);
    }

    int hash[maximum + 1];
    memset(hash, 0, (maximum + 1)*sizeof(int));

    for (int i = 0; i < n; i++){
        hash[arr[i]]++;
    }

    // iterate for all possible a
    for (int i = 1; i < maximum + 1; i++){
        if (hash[i] == 0){
            continue;
        }
        for (int j = 1; j < maximum + 1; j++){
            if ((i == j && hash[i] == 1) || hash[j] == 0){
                continue;
            }

            int val = sqrt(i * i + j * j);
            if ((val * val) != (i * i + j * j)) {
                continue;
            }

            if (val > maximum){
                continue;
            }

            if (hash[val]){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int arr[] = {3, 2, 4, 6, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    if (checkTriplet(arr, n)){
        cout << "Yes";
    } else {
        cout << "No";
    }
    if (isTriplet(arr, n)){
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
