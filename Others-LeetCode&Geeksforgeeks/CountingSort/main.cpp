#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * Counting Sort is a sorting technique based on keys between
 * a specific range. It works by counting the number of objects
 * having distinct key values (kind of hashing). Then doing some
 * aritmetic to calculate the position of each object in the output
 * sequence
 *
 */

// Sorting a string using Counting Sort
#define RANGE 255

void countingSort(char arr[]){
    char output[strlen(arr)];

    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    for (i = 0; arr[i]; ++i){
        ++count[arr[i]];
    }

    for (int i = 1; i <= RANGE; ++i){
        count[i] += count[i-1];
    }

    for (int i = 0; arr[i]; ++i){
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (int i = 0; arr[i]; ++i){
        arr[i] = output[i];
    }
}

// Sorting integers including negatives using Counting Sort
// store count of minimum element at zero index

void countingSortInts(vector<int>& arr){
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range), output(arr.size());

    for (int i = 0; i < arr.size(); i++){
        count[arr[i] - min]++;
    }

    for (int i = 1; i < count.size(); i++){
        count[i] += count[i-1];
    }

    for (int i = arr.size() -1; i >= 0; i--){
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < arr.size(); i++){
        arr[i] = output[i];
    }
}

int main()
{
    char arr[] = "testforcountingsort";
    countingSort(arr);
    cout << "Result is " << arr;
    cout << endl;

    vector<int> test = {-5, -10, 0, -3, 8, 5, -1, 10};
    countingSortInts(test);
    for (int i = 0; i < test.size(); i++){
        cout << test.at(i) << " ";
    }
    cout << endl;
    return 0;
}
