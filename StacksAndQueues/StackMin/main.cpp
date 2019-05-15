#include <iostream>
#include <stack>

using namespace std;

struct MyStack{
    stack<int> s1;
    stack<int> s2;
    int minVal;

    int min() {
        if (s1.empty()){
            return INT_MAX;
        } else {
            return s2.top();
        }
    }

    void push(int value){
        if(value <= min()) {
            s2.push(value);
        }
        s1.push(value);
    }

    void pop() {
        int value = s1.top();
        s1.pop();
        if(value == min()) {
            s2.pop();
        }
    }
};

int main()
{
    MyStack s;
    s.push(3);
    s.push(5);
    int min1 = s.min();
    cout << "min value1:" << min1 <<endl;
    s.push(2);
    s.push(-1);
    int min2 = s.min();
    cout << "min value2:" << min2 << endl;
    s.pop();
    int min3 = s.min();
    cout << "min value3:" << min3 << endl;
    return 0;
}
