#include <iostream>
#include <algorithm>

using namespace std;

int searchInRotataedArray(int *a, int left, int right, int value){
    if (right < left){
        return -1;
    }
    int mid = (right + left) / 2;
    if (value == a[mid]){
        return mid;
    }

    if (a[left] < a[mid]){
        if (value >= a[left] && value < a[mid]) {
            return searchInRotataedArray(a, left, mid-1, value);
        } else {
            return searchInRotataedArray(a, mid+1, right, value);
        }
    } else if (a[mid] < a[left]){
        if (value > a[mid] && value <= a[right]) {
            return searchInRotataedArray(a, mid+1, right, value);
        } else {
            return searchInRotataedArray(a, left, mid-1, value);
        }
    } else if (a[mid] == a[left]) {
        //left ir right half is all repeats
        // if right is different, search it
        if (a[mid] != a[right]) {
            //search right
            return searchInRotataedArray(a, mid+1, right, value);
        } else {
            //search both side
            int result = searchInRotataedArray(a, left, mid-1, value);
            if (result == -1){
                return searchInRotataedArray(a, mid+1, right, value);
            } else {
                return result;
            }
        }
    }
    return -1;
}

int main()
{
    int values[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int size = sizeof(values)/sizeof(*values);
    cout << "5 is at index " << searchInRotataedArray(values, 0, size-1, 5) << endl;
    return 0;
}
