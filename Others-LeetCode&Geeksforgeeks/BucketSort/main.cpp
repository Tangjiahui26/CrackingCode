#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Bucket sort is mainly useful when input is uniformly distributed
// over a range

// Problem: Sort a large set of floating point numbers which are in
// range from 0.0 to 1.0 and are uniformly distributed across the
// range.

void bucketSort(float arr[], int n){
    vector<float> b[n];

    for (int i = 0; i < n; i++){
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++){
        sort(b[i].begin(), b[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < b[i].size(); j++){
            arr[index++] = b[i][j];
        }
    }
}

// sort both positive and negative numbers

void bucketSortVector(vector<float> &arr, int n){
    vector<float> b[n];

    for (int i = 0; i < n; i++){
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++){
        sort(b[i].begin(), b[i].end());
    }

//    int index = 0;
    arr.clear();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < b[i].size(); j++){
            arr.push_back(b[i][j]);
        }
    }
}

void sortedMixed(float arr[], int n){
    vector<float> Neg;
    vector<float> Pos;

    for (int i = 0; i < n; i++){
        if (arr[i] < 0){
            Neg.push_back(-1 * arr[i]);
        } else {
            Pos.push_back(arr[i]);
        }
    }

    bucketSortVector(Neg, static_cast<int>(Neg.size()));
    bucketSortVector(Pos, static_cast<int>(Pos.size()));

    for (int i = 0; i < Neg.size(); i++){
        arr[i] = -1 * Neg[Neg.size() - 1 - i];
    }

    for (int j = Neg.size(); j < n; j++){
        arr[j] = Pos[j - Neg.size()];
    }
}

int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    float arr1[] = {-0.897, -0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n1 = sizeof(arr)/sizeof(arr[0]);
    sortedMixed(arr1, n1);

    cout << "Sorted array is \n";
    for (int i = 0; i < n1; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    return 0;
}
