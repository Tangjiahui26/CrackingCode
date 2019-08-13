#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//brute force:
//will have duplicates

vector<pair<int, int>> pairsWithSum(vector<int>& arr, int sum){
    vector<pair<int, int>> res;
    for (size_t i = 0; i < arr.size(); i++){
        for (size_t j = i + 1; j < arr.size(); j++){
            if(arr.at(i) + arr.at(j) == sum) {
                res.push_back(make_pair(arr.at(i), arr.at(j)));
            }
        }
    }
    return res;
}

//hashtable runtime O(n), space O(n)

/***
 * many duplicates
 *
 ***/
//unordered_set<int> createSet(vector<int>& arr){
//    unordered_set<int> res;
//    for (auto r : arr){
//        res.insert(r);
//    }
//    return res;
//}

//vector<pair<int, int>> pairsWithSumWithHashtable(vector<int>& arr, int sum){
//    unordered_set<int> s = createSet(arr);
//    vector<pair<int, int>> res;
//    for (auto val : arr){
//        int complement = sum - val;
//        if (s.find(complement) != s.end()){
//            res.push_back(make_pair(val, complement));
//        }
//    }
//    return res;
//}


//sorting then search from start and end positions (or binary search the complement directly) O(nlog(n))

vector<pair<int, int>> pairsWithSumSorting(vector<int>& arr, int sum){
    vector<pair<int, int>> res;
    sort(arr.begin(), arr.end());
    int first = 0;
    int last = arr.size() - 1;
    while (first < last){
        int s = arr.at(first) + arr.at(last);
        if (s == sum){
            res.push_back(make_pair(arr.at(first), arr.at(last)));
            first++;
            last--;
        } else {
            if (s < sum){
                first++;
            } else {
                last--;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> test = {1, -6, 2, 9, 3, 4, -2, 5, 6};
    int sum = 5;
    vector<pair<int, int>> res = pairsWithSumSorting(test, sum);
    for (auto r : res){
        cout << r.first << ", " << r.second << endl;
    }
    return 0;
}
