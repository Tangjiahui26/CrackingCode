#include <iostream>
#include <stack>

using namespace std;

struct Queue{
    stack<int> s1, s2;

    void enQueue(int x) {
        s1.push(x);
    }

    int deQueue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty" << endl;
            exit(0);
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int returnValue = s2.top();
        s2.pop();
        return returnValue;
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    return 0;
}
