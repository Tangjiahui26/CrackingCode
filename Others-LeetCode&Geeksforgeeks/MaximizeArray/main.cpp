#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Given two arrays with size n, maximize the first array by using
// the elements from the second array such that the new array formed
// contains n greatest but unique elements of both the arrays.

// giving the second array priority (All elements of second array appear
// before first array). The order of appearance of elements is kept same
// in output as in input.

// solution: using an extra array with 2*n size

bool compare(int a, int b){
    return a > b;
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void maximizeArray(int arr1[], int arr2[], int n){
    int arr3[2*n], k = 0;
    for (int i = 0; i < n; i++){
        arr3[k++] = arr1[i];
    }
    for (int i = 0; i < n; i++){
        arr3[k++] = arr2[i];
    }

    // using a hashtable to store n largest unique elements
    unordered_set<int> ht;

    // sort array3
    sort(arr3, arr3 + 2 * n, compare);

    // finding n largest unique elements from array3 and sorting in hash
    int i = 0;
    while(ht.size() != n){
        if (ht.find(arr3[i]) == ht.end()) {
            ht.insert(arr3[i]);
        }

        i++;
    }

    // store that elements of array2 in array3 that are present in hashtable
    k = 0;
    for (int i = 0; i < n; i++){
        if (ht.find(arr2[i]) != ht.end()) {
            // if presents, store it in arr3
            arr3[k++] = arr2[i];
            ht.erase(arr2[i]);
        }
    }

    for (int i = 0; i < n; i++){
        if (ht.find(arr1[i]) != ht.end()){
            arr3[k++] = arr1[i];
            ht.erase(arr1[i]);
        }
    }

    for (int i = 0; i < n; i++){
        arr1[i] = arr3[i];
    }
}

int main()
{
    int array1[] = {7, 4, 8, 0, 1};
    int array2[] = {9, 7, 2, 3, 6};
    int size = sizeof(array1)/sizeof(array1[0]);
    maximizeArray(array1, array2, size);
    printArray(array1, size);
    return 0;
}
