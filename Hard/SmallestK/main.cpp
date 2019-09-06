#include <iostream>

using namespace std;

// Write an efficient program for printing k largest/smallest elements in an array.
// Elements in array can be in any order

// here we want to print k largest elements

// method1: use bubble k times - O(nk)
/*
 * 1. Modify Bubble sort to run the outer loop at most k times
 * 2. Print the last k elements of the array obtained in step 1
 */

// method2: use temporary array - O((n-k)*k)
/* 1. Store the first k elements in a temporary array temp[0..k-1]
 * 2. Find the smallest element in temp[], let the smallest be min
 * 3. a. for each element x in arr[k] to arr[n-1], if x is greater than
 *       the min, then remove min from temp[] and insert x.
 *    b. Then determin the new min from temp[]
 * 4. print final k elements of temp[]
 */

//method3: use sorting
/* Sort the elements in descending order in O(nlogn)
 * print the first k number of the sorted array O(k)
 */

void kLargest(int arr[], int n, int k){
    sort(arr, arr + n, greater<int>());

    for (int i = 0; i < k; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//method4: use max heap (easy to build using priorityQueue in JAVA)
/*
 * 1. build a max heap tree in O(n)
 * 2. User extract max k times to get k maximum elements from the max heap O(klogn)
 *
 * For k smallest, use min heap instead.
 */

//method5: ise min heap (for k smallest, same idea but using max heap) - modification of method1
/*
 * 1. Build a min heap MH of the first k elements (arr[0] to arr[k-1]) - O(k)
 * 2. For each element, after the kth elemnt (arr[k] to arr[n-1]), compare it with root of MH
 *    a. if greater, then make it root and call heapify for MH (poll in JAVA)_
 *    b. Else ingore it.
 * 3. Finally, MH has k largest elements and root of the MH is the kth largest element.
 *
 * Time Complexity: O(k + (n-k)Logk) without sorted output.
 */

int swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

class MinHeap{
    int size;
    int* arr;
public:
    MinHeap(int size, int input[]);

    // min heapify function, that assumes that 2*i+1 and 2*i+2 are min heap and
    // dix the heap property for i.
    void heapify(int i);

    void buildHeap();
};

MinHeap::MinHeap(int size, int input[]){
    this->size = size;
    this->arr = input;
    buildHeap();
}

void MinHeap::heapify(int i){
    // If leaf Node, Simply return
    if (i >= size /2){
        return;
    }

    // variable to store the smallest element
    // index out of i, 2*i+1 and 2*i+2
    int smallest;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    smallest = arr[left] < arr[i] ? left : 1;

    // if right child exists
    if (right < size){
        smallest = arr[right] < arr[smallest] ? right : smallest;
    }

    if (smallest != i){
        swap(arr[i], arr[smallest]);
        // recursively call heapify for node smallest
        heapify(smallest);
    }
}

void MinHeap::buildHeap(){
    // heapify for all non leaf nodes
    for (int i = size /2 -1; i>= 0; i--){
        heapify(i);
    }
}

void FirstKelements(int arr[], int size, int k){
    MinHeap* m = new MinHeap(k, arr);
    // Loop for each element in array after the kth element
    for (int i = k; i < size; i++){
        if (arr[0] > arr[i]){
            continue;
        } else {
            arr[0] = arr[i];
            m->heapify(0);
        }
    }

    for (int i = 0; i < k; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//method6: Selection Rank (for finding ith smallest)
/* 1. Pick a random element in the array and use it as a "pivot". Partition elements
 *    around the pivot, keeping track of thr number of elements on the left side of the partition
 * 2. IF there are extacly i elements on the left, then you just return the biggest on the left
 * 3. If the left side is bigger than i, repeat the algorithm on just the left part of the array
 * 4. If the left side is samller than i, repeat the algorithm on the right, but look for the element
 *    with rank i - leftSize.
 *
 * 5. print all the elements smaller than ith smallest.
 */

int main()
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    kLargest(arr, n, k);
    FirstKelements(arr, n, k);
    return 0;
}
