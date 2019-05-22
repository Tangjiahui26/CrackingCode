#include <iostream>
#include <stack>
#include <climits>
#define MAXSIZE 20

using namespace std;

class MyStack {
    stack<int> mystack;
public:
    void push(int e){
        mystack.push(e);
    }

    int pop(){
        if (!mystack.empty()) {
            int k = mystack.top();
            mystack.pop();
            return k;
        }
        return -1;
    }

    bool full() {
        if (mystack.size() > MAXSIZE - 1) {
            return true;
        } else {
            return false;
        }
    }

    bool empty() {
        return mystack.empty();
    }
};

// linked list
struct stackPoint {
    MyStack * currentStack;
    stackPoint * nextStackPoint;
};

class SetofStacks{
private:
    stackPoint *sp;
    int numOfStack;
public:
    SetofStacks() {
        sp = new stackPoint;
        sp->currentStack = new MyStack;
        sp->nextStackPoint = NULL;
        numOfStack = 1;
    }

    bool push(int e) {
        if (sp->currentStack->full()) {
            stackPoint *t = new stackPoint;
            t->currentStack = new MyStack;
            t->currentStack->push(e);

            t->nextStackPoint = sp;
            sp = t;
            numOfStack++;
        } else {
            sp->currentStack->push(e);
        }
        return true;
    }

    int pop() {
        if (sp->currentStack->empty()) {
            stackPoint *t = sp;
            sp = sp->nextStackPoint;
            delete t;
            numOfStack--;
            return sp->currentStack->pop();
        } else {
            return sp->currentStack->pop();
        }
    }

    // Might not be correct
    int popAt(int index) {
        int ind = numOfStack - index;
        if (ind < 0) {
            return INT_MIN;
        }

        stackPoint *t = sp;
        while (ind > 0) {
            ind--;
            t = t->nextStackPoint;
        }
        return t->currentStack->pop();
    }

    int getNumOfStack() {
        return numOfStack;
    }

    bool empty() {
        if (numOfStack == 1 && sp->currentStack->empty()){
            return true;
        } else {
            return false;
        }
    }
};

int main()
{
    SetofStacks s;
    for (int i = 0; i < 55; i++) {
        s.push(i);
    }

    while (!s.empty()) {
        cout << s.pop() << " ";
    }
    cout << '\n';
    return 0;
}
