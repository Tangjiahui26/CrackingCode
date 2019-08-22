#include <iostream>

using namespace std;

// recursively

int cuttingRod(int price[], int n){
    if (n <= 0){
        return 0;
    }
    int maxVal = INT_MIN;

    for (int i = 0; i < n; i++){
        maxVal = max(maxVal, price[i] + cuttingRod(price, n - i - 1));
    }
    return maxVal;
}

// Dynamic Programming
// runtime O(n^2)

int cuttingRodDP(int price[], int n){
    int val[n+1];
    val[0] = 0;
    int i, j;

    for (i = 1; i <=n; i++){
        int maxVal = INT_MIN;
        for (j = 0; j < i; j++){
            maxVal = max(maxVal, price[j] + val[i - j - 1]);
        }
        val[i] = maxVal;
    }
    return val[n];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum obtainable value is " << cuttingRod(arr, size) << endl;
    cout << "Maximum obtainable value is " << cuttingRodDP(arr, size) << endl;
    return 0;
}
