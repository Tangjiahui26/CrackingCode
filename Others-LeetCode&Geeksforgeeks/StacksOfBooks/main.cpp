#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// sort a stack with a temp
stack<int> sortStack(stack<int> & input){
    stack<int> tempStack;

    while(!input.empty()){
        int temp = input.top();
        input.pop();

        while (!tempStack.empty() && tempStack.top() < temp) {
            input.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }
    return tempStack;
}

int maxBooks(stack<int>& arr1, stack<int>& arr2, int max){
    stack<int> sortedArr1 = sortStack(arr1);
    stack<int> sortedArr2 = sortStack(arr2);

    int count = 0;
    int maxVal = 0;
    while (!sortedArr1.empty() && !sortedArr2.empty()){
        maxVal += sortedArr1.top();
        maxVal += sortedArr2.top();
        if (maxVal <= max){
            count += 2;
            sortedArr1.pop();
            sortedArr2.pop();
        } else {
            int bigger = std::max(sortedArr1.top(), sortedArr2.top());
            if (maxVal - bigger <= max){
                maxVal -= bigger;
                count += 1;
                if (bigger == sortedArr1.top()) {
                    sortedArr2.pop();
                } else {
                    sortedArr1.pop();
                }
            }
            break;
        }
    }
    return count;
}

int main()
{
    stack<int> book1;
    book1.push(3);
    book1.push(6);
    book1.push(3);
    book1.push(2);
    book1.push(5);

    stack<int> book2;
    book2.push(15);
    book2.push(1);
    book2.push(1);
    book2.push(1);
    book2.push(1);
    book2.push(1);
    book2.push(1);
    book2.push(9);

    stack<int> book3;
    book3.push(5);
    book3.push(1);
    book3.push(1);

    stack<int> book4;
    book4.push(1);
    book4.push(2);
    book4.push(6);


    cout << maxBooks(book1, book2, 15) << endl;
    cout << maxBooks(book3, book4, 10) << endl;
    return 0;
}
