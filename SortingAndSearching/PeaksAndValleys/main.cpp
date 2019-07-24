#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// approach 1: sort the array then swap (n, n-1) where n is odd.
// time complexity : O(nlog(n))

void swap(vector<int>& arr, int left, int right){
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

void peaksAndValleys(vector<int>& arr){
    sort(arr.begin(), arr.end());
    for (size_t i = 1; i < arr.size(); i +=2){
        swap(arr, i-1, i);
    }
}

//int main()
//{
//    vector<int> arr = {4, 1, 0, 7, 8, 9};
//    peaksAndValleys(arr);
//    for (size_t i = 0; i < arr.size(); i++){
//        cout << arr[i];
//    }
//    cout << endl;
//    return 0;
//}

// approach 2: cut out the sorting step
// swap biggest with the central value if the central value is not the biggest
// O(n) runtime

int findMaxIndex(vector<int> &arr, int a, int b, int c){
    int len = arr.size();
    int aValue = a >=0 && a < len ? arr[a] : INT_MIN;
    int bValue = b >=0 && b < len ? arr[b] : INT_MIN;
    int cValue = c >=0 && c < len ? arr[c] : INT_MIN;

    int maxValue = max(aValue, max(bValue, cValue));
    if (maxValue == aValue) {
        return a;
    } else if (bValue == maxValue) {
        return b;
    } else {
        return c;
    }
}

void peaksAndValleysWithoutSorting(vector<int>& arr){
    for (size_t i = 1; i < arr.size(); i +=2){
        int biggestIndex = findMaxIndex(arr, i - 1, i, i + 1);
        if (i != biggestIndex){
            swap(arr, i, biggestIndex);
        }
    }
}

int main()
{
    vector<int> arr = {9, 1, 0, 4, 8, 7};
    peaksAndValleysWithoutSorting(arr);
    for (size_t i = 0; i < arr.size(); i++){
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
