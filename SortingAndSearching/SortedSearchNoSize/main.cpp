#include <iostream>
#include <algorithm>

using namespace std;

struct Listy {
    int values[10] = {1, 2, 3, 5, 6, 19, 21, 35, 44, 50};
    int size = 10;
    // elementAt()
     int operator [](int idx) const {
        return idx < size ? values[idx] : -1;
    }
};

int binarySearch(const Listy& list, int value, int low, int high){
    int mid;
    while (low <= high) {
        mid = (high + low)/2;
        int middle = list[mid];
        //if the mid point is -1, we need to threat this as a "too big" value and search left
        if (middle > value || middle == -1){
            high = mid - 1;
        } else if (middle < value){
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int sortedSearchNoSize(const Listy& list, int value){
    int index = 1;
    while(list[index] != -1 && list[index] < value){
        index *=2;
    }
    return binarySearch(list, value, index/2, index);
}

int main()
{
    Listy list;
    cout << "44 is at index " << sortedSearchNoSize(list, 44) << endl;
    return 0;
}
