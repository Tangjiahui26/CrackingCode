#include <iostream>
#include <algorithm>

using namespace std;

// brute force

int smallestDifference(int* arr1, int* arr2, int size1, int size2){
    if (size1 == 0 || size2 == 0){
        return -1;
    }

    int min = INT_MAX;
    for (int i = 0; i < size1; ++i){
        for (int j = 0; j < size2; ++j){
            if (abs(arr1[i] - arr2[j]) < min){
                min = abs(arr1[i] - arr2[j]);
            }
        }
    }
    return min;
}

// optimal by sorting first

int smallestDifferenceWithSorting(int* arr1, int* arr2, int size1, int size2){
    sort(arr1, arr1+size1);
    sort(arr2, arr2+size2);

    int a = 0, b = 0;
    int min = INT_MAX;
    while(a < size1 && b < size2){
        if (abs(arr1[a] - arr2[b]) < min){
            min = abs(arr1[a] - arr2[b]);
        }

    if (arr1[a] < arr2[b]){
            a++;
        } else {
            b++;
        }
    }
    return min;
}

int main()
{
    int test1[] = {1, 3, 15, 11, 2};
    int test2[] = {23, 127, 235, 19, 8};
    cout << "Result: " << smallestDifference(test1, test2,
                                             sizeof(test1)/sizeof(*test1),
                                             sizeof(test2)/sizeof(*test2)) << endl;
    cout << "Result: " << smallestDifferenceWithSorting(test1, test2,
                                             sizeof(test1)/sizeof(*test1),
                                             sizeof(test2)/sizeof(*test2)) << endl;
    return 0;
}
