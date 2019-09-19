#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

// naive solution: O(N^2)

void stockSpan(int price[], int n, int S[]){
    S[0] = 1;

    for (int i = 1; i < n; i++){
        S[i] = 1;
        for (int j = i -1; (j >= 0) && (price[i] >= price[j]); j--){
            S[i]++;
        }
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

// A linear time complexity method - O(N)
// Using a stack - O(N) extra space

void stockSpanUsingStack(int price[], int n, int S[]){
    // store the index
    stack<int> st;
    st.push(0);

    S[0] =1;

    for (int i = 1; i < n; i++){
        while(!st.empty() && price[st.top()] <= price[i]){
            st.pop();
        }

        S[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }
}

// linear time without using stack

void stockSpanWithoutStack(int price[], int n, int S[]){
    S[0] = 1;

    for (int i = 1; i < n; i++){
        int counter = 1;

        while((i - counter) >= 0 && price[i] > price[i-counter]){
            counter += S[i - counter];
        }
        S[i] = counter;
    }
}

int main()
{
    int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price)/sizeof(price[0]);
    int S[n];

//    stockSpan(price, n, S);
//    stockSpanUsingStack(price, n ,S);
    stockSpanWithoutStack(price, n, S);

    printArray(S, n);
    return 0;
}
