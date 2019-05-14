#include <iostream>

using namespace std;

// For this exercise, a generic version of k stacks in an array
// problem is sloved.

class kStacks {
    int *arr;
    int *top;
    int *next;

    int n, k;
    int free;
public:
    kStacks(int k, int n);
    bool isFull() {return (free == -1);}

    void push(int item, int sn);
    int pop(int sn);
    bool isEmpty(int sn) {return (top[sn] == -1);}
};

kStacks::kStacks(int k1, int n1) {
    k=k1, n=n1;
    arr = new int[n];
    top = new int[k];
    next = new int[n];

    //Initialize all stacks as empty
    for (int i = 0; i < k; i++){
        top[i] = -1;
    }

    //Initialize all space as free
    free = 0;
    for (int i = 0; i < n - 1; i++) {
        next[i] = i + 1;
    }
    next[n-1] = -1; // -1 is used to indicate end of free list
}

void kStacks::push(int item, int sn){
    if(isFull()){
        cout << "\nStack Overflow\n";
        return;
    }

    int i = free;
    free = next[i];

    next[i] = top[sn];
    top[sn] = i;

    arr[i] = item;
}

int kStacks::pop(int sn) {
    if(isEmpty(sn)) {
        cout <<"\nStack Underflow\n";
        return INT_MAX;
    }

    int i = top[sn];
    top[sn] = next[i];

    next[i] = free;
    free = i;

    return arr[i];
}


int main()
{
    // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    kStacks ks(k, n);

    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);

    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    return 0;
}
