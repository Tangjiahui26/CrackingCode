#include <iostream>
#include <queue>

using namespace std;

// Given that integers are being read from a data stream,
// Find median of all the elements read so far start from the first
// integer till the last integer.

// solution: Using max heap + min heap to store the elements
// of higher half and lower half.

void printMedians(double arr[], int n){
    // max heap to store the smaller half elements
    priority_queue<double> s;

    // min heap to store the greater half elements
    priority_queue<double, vector<double>, greater<double>> g;

    double med = arr[0];
    s.push(arr[0]);

    cout << med << endl;

    for (int i = 1; i < n; i++){
        double x = arr[i];

        // if left side heap has more element
        if (s.size() > g.size()){
            if (x < med){
                // pop the top of max heap and insert into min heap
                g.push(s.top());
                s.pop();
                // insert the new to max heap
                s.push(x);
            } else {
                g.push(x);
            }
            med = (s.top() + g.top()) / 2.0;
        } // both are balanced
        else if (s.size() == g.size()){
            if (x < med){
                s.push(x);
                med = (double)s.top();
            } else {
                g.push(x);
                med = (double)g.top();
            }
        } // right side heap has more elements
        else {
            if (x > med){
                s.push(g.top());
                g.pop();
                g.push(x);
            } else {
                s.push(x);
            }
            med = (s.top() + g.top()) / 2.0;
        }
        cout << med << endl;
    }
}

int main()
{
    double arr[] = {5, 15, 10, 20, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMedians(arr, n);
    return 0;
}
