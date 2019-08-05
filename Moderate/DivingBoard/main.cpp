#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

// recursive solution
// runtime: O(2^K)

void getAllLengths(int k, int total, int shorter, int longer, unordered_set<int>& lengths){
    if (k == 0){
        lengths.insert(total);
        return;
    }
    getAllLengths(k - 1, total+shorter, shorter, longer, lengths);
    getAllLengths(k - 1, total+longer, shorter, longer, lengths);
}

unordered_set<int> divingBoard(int k, int shorter, int longer){
    unordered_set<int> lengths;
    getAllLengths(k, 0, shorter, longer, lengths);
    return lengths;
}

// DP (memorization)
// runtime: O(K^2)

void getAllLengthsDP(int k, int total, int shorter, int longer, unordered_set<int>& lengths, unordered_set<string>& visited){
    if (k == 0){
        lengths.insert(total);
        return;
    }
    string key = to_string(k) + " " + to_string(total);
    if (visited.find(key) != visited.end()){
        return;
    }
    getAllLengths(k - 1, total+shorter, shorter, longer, lengths);
    getAllLengths(k - 1, total+longer, shorter, longer, lengths);
    visited.insert(key);
}

unordered_set<int> divingBoardDP(int k, int shorter, int longer){
    unordered_set<int> lengths;
    unordered_set<string> visited;
    getAllLengthsDP(k, 0, shorter, longer, lengths, visited);
    return lengths;
}

// optimal
// since there are only K sums, so we can just iterate and get all the possible sums
// could use vector<int> instead, but we need to deal with corner case where shorter and longer are the same

unordered_set<int> divingBoardOptimal(int k, int shorter, int longer){
    unordered_set<int> lengths;
    for (int nShorter = 0; nShorter <= k; nShorter++){
        int nLonger = k - nShorter;
        int length = nShorter * shorter + nLonger * longer;
        lengths.insert(length);
    }
    return lengths;
}


int main()
{
    int k = 3;
    int shorter = 1;
    int longer = 2;
    unordered_set<int> result = divingBoardOptimal(k, shorter, longer);
    for (auto r : result){
        cout << r << endl;
    }
    return 0;
}
