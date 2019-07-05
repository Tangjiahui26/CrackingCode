#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// binary search
int * magicIndex(int * numbers, int start, int end){
    if (end < start) {
        return NULL;
    }

    int mid = (end + start) / 2;
    int mid_val = numbers[mid];
    if (mid_val == mid) {
        return numbers + mid;
    } else if (mid_val > mid) {
        return magicIndex(numbers, start, mid - 1);
    } else {
        return magicIndex(numbers, mid + 1, end);
    }

    return NULL;
}

// follow-ups: elements are not distinct
int * magicIndexNotDistinct(int * numbers, int start, int end){
    if (end < start) {
        return NULL;
    }

    int mid = (end + start) / 2;
    int mid_val = numbers[mid];

    if (mid_val == mid) {
        return numbers + mid;
    }

    if (int * left = magicIndexNotDistinct(numbers, start, min(mid - 1, mid_val))){
        return left;
    }
    return magicIndexNotDistinct(numbers, max(mid + 1, mid_val), end);
}

int main()
{
    int num1[] = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
    int count1 = sizeof(num1) /sizeof(*num1);
    int * magic1 = magicIndex(num1, 0, count1 - 1);
    int value1 = magic1 ? *magic1 : -1;
    cout << "Magic Index: " << value1 << endl;

    int num2[] = {-10, -5, 1, 2, 2, 3, 4, 7, 9, 12, 13};
    int count2 = sizeof(num2) /sizeof(*num2);
    int * magic2 = magicIndexNotDistinct(num2, 0, count2 - 1);
    int value2 = magic2 ? *magic2 : -1;
    cout << "Magic Index (not unique): " << value2 << endl;
    return 0;
}
