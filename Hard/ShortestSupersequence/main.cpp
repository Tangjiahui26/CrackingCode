#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

// brute force

int findNextInstance(vector<int> arr, int element, int index){
    for (int i = index; i < arr.size(); i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int findClosure(vector<int> bigArray, vector<int> smallArray,int index){
    int max = -1;
    for (int i = 0; i < smallArray.size(); i++){
        int next = findNextInstance(bigArray, smallArray[i], index);
        if (next == -1){
            return -1;
        }
        max = std::max(next, max);
    }
    return max;
}

pair<int, int> shortestSupersequence(vector<int> bigArray, vector<int> smallArray){
    int bestStart = -1;
    int bestEnd = -1;
    for (int i = 0; i < bigArray.size(); i++){
        int end = findClosure(bigArray, smallArray, i);
        if (end == -1) break;
        if (bestStart == -1 || end - i < bestEnd - bestStart){
            bestEnd = end;
            bestStart = i;
        }
    }
    return make_pair(bestStart, bestEnd);
}

// Discussion about optimal solutions:
// https://www.reddit.com/r/algorithms/comments/7sqa2p/shortest_supersequence/

int main()
{
    vector<int> big = {7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7};
    vector<int> small = {1,5,9};
    pair<int, int> res = shortestSupersequence(big, small);
    cout << res.first << "-" << res.second << endl;
    return 0;
}
