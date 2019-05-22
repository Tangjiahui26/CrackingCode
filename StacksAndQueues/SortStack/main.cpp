#include <iostream>
#include <stack>

using namespace std;

stack<int> sortStack(stack<int> &s) {
    stack<int> temp;

    while(!s.empty()) {
        int tem = s.top();
        s.pop();

        while(!temp.empty() && tem > temp.top()) {
            s.push(temp.top());
            temp.pop();
        }

        temp.push(tem);
    }

    return temp;
}

int main()
{
    stack<int> input;
    input.push(33);
    input.push(2);
    input.push(12);
    input.push(-4);
    input.push(23);
    input.push(12);

    stack<int> result = sortStack(input);

    cout << "Sorted Stack: TOP->BOTTOM: ";
    while(!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
    cout << endl;
    return 0;
}
