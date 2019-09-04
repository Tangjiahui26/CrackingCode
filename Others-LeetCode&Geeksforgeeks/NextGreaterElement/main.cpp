#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

// problem: Given an array, print the next great element for every element.
// The next greater Element for an element x is the first greater element
// on the right side of x in array. Elements for which no greater element
// exist, consider next greater element as -1

// Examples:
// 1. For any array, rightmost element always has next greater element as -1.
// 2. For an array which is sorted in descending order, all elements have
//    next greater element as -1.
// 3. For the input array [4, 5, 2, 25}, the next element for each element are
//   as follows: 4->5, 5->25, 2->25, 25->-1
// 4. For the input array [13, 7, 6, 12}, the next greater elements for each
//   element are as follows: 13->-1, 7->12, 6->12, 12->-1

// simple method: O(n^2) two loops
void printNGE(int arr[], int n){
    int next, i, j;
    for (i = 0; i < n; i++){
        next = -1;
        for(j=i+1; j < n; j++){
            if (arr[i] < arr[j]){
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << "-->" << next << endl;
    }
}

// method 2: using Stack
/* 1. pushing the first element to stack
   2. pick rest of the elements one by one and follow the following steps in loop
      I. Mark the current element as next
      II. If stack is not empty, compare top element of stack with next
      III. If next is greater, Pop element from stack. next is the next greater element for the popped element
      IV. Keep popping from the stack while the popped element is smaller than next. next becomes the NGE for all such popped elements
   3. Finally, push the next in the stack
   4. After the loop in step 2 is over, pop all the elements from stack and print -1 as NGE
   */


// runtime O(n)
void printNGEUsingStack(int arr[], int n){
    stack<int> s;
    s.push(arr[0]);

    for (int i = 1; i < n; i++){
        if (s.empty()){
            s.push(arr[i]);
            continue;
        }

        while (!s.empty() && s.top() < arr[i]){
            cout << s.top() << "-->" << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]);
    }

    while (!s.empty()){
        cout << s.top() << "-->" << -1 << endl;
        s.pop();
    }
}


int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    cout << "-------" << endl;
    printNGEUsingStack(arr, n);
    return 0;
}
