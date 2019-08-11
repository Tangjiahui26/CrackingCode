#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <unordered_set>

using namespace std;

// brute force O(AB)
// naive way: newSum1 == newSum2

pair<int, int> sumSwap(vector<int> arr1, vector<int> arr2){
    int sum1 = accumulate(arr1.begin(), arr1.end(), 0);
    int sum2 = accumulate(arr2.begin(), arr2.end(), 0);

    for (auto one : arr1){
        for (auto two : arr2){
            int newSum1 = sum1 - one + two;
            int newSum2 = sum2 - two + one;
            if (newSum1 == newSum2){
                return make_pair(one, two);
            }
        }
    }
    return pair<int, int>(INT_MAX, INT_MAX);
}

// target approach: O(AB)

int getTarget(vector<int> arr1, vector<int> arr2){
    int sum1 = accumulate(arr1.begin(), arr1.end(), 0);
    int sum2 = accumulate(arr2.begin(), arr2.end(), 0);

    if ((sum1 - sum2)% 2 != 0){
        return INT_MAX;
    } else {
        return (sum1 - sum2) /2;
    }
}

pair<int, int> sumSwapTarget(vector<int> arr1, vector<int> arr2){
    int target = getTarget(arr1, arr2);
    if (target == INT_MAX ){
        return pair<int, int>(INT_MAX, INT_MAX);
    }

    for (auto one : arr1){
        for (auto two : arr2){
            if (one -two == target){
                return make_pair(one, two);
            }
        }
    }
    return make_pair(INT_MAX, INT_MAX);
}

//optimal solutions: O(A+B) with a hashtable to search

unordered_set<int> getContents(vector<int> arr){
    unordered_set<int> s;
    for (auto i : arr){
        s.insert(i);
    }
    return s;
}

pair<int, int> findDifference(vector<int>arr1, vector<int> arr2, int target){
    unordered_set<int> s = getContents(arr2);
    for (auto one : arr1){
        int two = one - target;
        if (s.find(two) != s.end()){
            return make_pair(one, two);
        }
    }
    return make_pair(INT_MAX, INT_MAX);
}

pair<int, int> findSumSwap(vector<int> arr1, vector<int> arr2){
    int target = getTarget(arr1, arr2);
    if (target == INT_MAX){
        return make_pair(INT_MAX, INT_MAX);
    }
    return findDifference(arr1, arr2, target);
}

int main()
{
    vector<int> test1 = {1, 3, 1, 2, 1, 1, 2};
    vector<int> test2 = {3, 6, 3, 3};
    pair<int, int> res = findSumSwap(test1, test2);
    cout << res.first << " " << res.second << endl;
    return 0;
}
