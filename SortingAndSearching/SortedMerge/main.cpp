#include <iostream>

using namespace std;

//merge from the back of arrays

void sortedMerge(int* a, int* b, int lastA, int lastB){
    int indexA = lastA - 1;
    int indexB = lastB - 1;
    int indexMerged = lastA + lastB - 1;

    while (indexB >= 0){
        if (indexA >= 0 && a[indexA] > b[indexB]) {
            a[indexMerged] = a[indexA];
            indexA--;
        } else {
            a[indexMerged] = b[indexB];
            indexB--;
        }
        indexMerged--;
    }
}

int main()
{
    int test1[] = {1, 2, 3, 5, 12, 15, 0, 0, 0, 0};
    int test2[] = {4, 6, 7, 8};
    int test1_length = sizeof(test1) /sizeof(*test1);
    int test2_length = sizeof(test2) /sizeof(*test2);

    test1_length -= test2_length;

    sortedMerge(test1, test2, test1_length, test2_length);

    for (int i : test1) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
