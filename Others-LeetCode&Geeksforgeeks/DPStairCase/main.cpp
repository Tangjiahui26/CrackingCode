#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// problem 1: only 1 or 2 steps at one time

int numberOfWays(int n){
    if (n == 0 || n == 1){
        return 1;
    } else {
        return numberOfWays(n-1) + numberOfWays(n-2);
    }
}

int numberOfWaysDP(int n){
    if (n == 0 || n == 1){
        return 1;
    }

    int nums[n+1];
    nums[0] = 1;
    nums[1] = 1;
    for (int i = 2; i <= n; i++){
        nums[i] = nums[i-1] + nums[i-2];
    }
    return nums[n];
}

// problem 2: given a set of possible steps X.

int numberofWaysGivenStepsDP(int n, vector<int> steps){
    if (n == 0){
        return 1;
    }
    int nums[n+1];
    nums[0] = 1;
    for (int i = 1; i <= n; i++){
        int total = 0;
        for (auto s : steps){
            if (i - s >= 0){
                total += nums[i-s];
            }
        }
        nums[i] = total;
    }
    return nums[n];
}

int main()
{
    cout << numberOfWays(4) << endl;
    cout << numberOfWaysDP(4) << endl;
    cout << numberofWaysGivenStepsDP(4, vector<int>({1, 3, 5})) << endl;
    return 0;
}
