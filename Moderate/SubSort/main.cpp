#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getEndOfLeftSubsequence(vector<int>& arr){

    for (size_t i = 1; i < arr.size(); i++){
        if (arr[i] < arr[i - 1]){
            return i - 1;
        }
    }
    return arr.size() - 1;
}

int getStartOfRightSubsequence(vector<int>& arr){

    for (size_t i = arr.size() - 2; i >= 0; i--){
        if (arr[i] > arr[i+1]){
            return i + 1;
        }
    }
    return 0;
}

int shrinkLeft(vector<int>& arr, int min_index, int start){
    int num = arr[min_index];
    for (int i = start - 1; i >= 0; i--){
        if (arr[i] <= num){
            return i + 1;
        }
    }
    return 0;
}

int shrinkRight(vector<int>& arr, int max_index, int start){
    int num = arr[max_index];
    for (size_t i = start; i < arr.size(); i++){
        if (arr[i] >= num){
            return i - 1;
        }
    }
    return arr.size() - 1;
}

void subSort(vector<int>& arr){
    int end_left = getEndOfLeftSubsequence(arr);
    if (static_cast<size_t>(end_left) >= arr.size() -1){
        return;
    }

    int start_right = getStartOfRightSubsequence(arr);
    int max_index = end_left;
    int min_index = start_right;
    for (int i = end_left + 1; i < start_right; i++){
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
        if (arr[i] > arr[max_index]){
            max_index = i;
        }
    }

    int left = shrinkLeft(arr, min_index, end_left);
    int right = shrinkRight(arr, max_index, start_right);
    cout << "(" << left << ", " << right << ")" << endl;
}

int main()
{
    vector<int> test = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    subSort(test);
    return 0;
}
