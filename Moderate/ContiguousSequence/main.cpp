#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Example:
// 2, 3, -8, -1, 2, 4, -2, 3
// Then we can reduce the array to alternating sequences of positive and negative numbers, as
// 5, -9, 6, -2, 3

// Then we have sum = 0, maxSum =0

// when we get a 5, we can update sum = 5, maxSum =5
// next, with -9, we can update sum = 0 (since sum = -4 < 0, then it is better to reset it), maxSum = 5 (since maxSum >= sum)
// next, with 6, then sum = 6, maxSum = 6
// next, with -2, sum = 4, maxSum = 6
// finally, with a 3, then sum = 7, maxSum = 7
// return maxSum

int getMaxSum(vector<int> arr){
    int sum = 0;
    int maxSum = 0;
    for (size_t i = 0; i < arr.size(); i++){
        sum += arr[i];
        if (maxSum < sum){
            maxSum = sum;
        } else if (sum < 0){
            sum = 0;
        }
    }
    return maxSum;
}

int main()
{
    vector<int> test1 = {2, 3, -8, -1, 2, 4, -2, 3};
    vector<int> test2 = {2, -8, 3, -2, 4, -10};
    cout << getMaxSum(test1) << endl;
    cout << getMaxSum(test2) << endl;
    return 0;
}
