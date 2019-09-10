#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// problem: given a string b and an array of smaller strings T, design
// a method to search b for each small string in T.

// brute force - O(kbt) where k is the length of longest string in T
// b is the length of the bigger string
// t is the number of smaller strings within T

bool isSubstringAtLocation(string big, string small, int offset){
    for (int i = 0; i < small.size(); i++){
        if(big[offset+i] != small[i]){
            return false;
        }
    }
    return true;
}

vector<int> search(string big, string small){
    vector<int> result;
    for (int i = 0; i < big.size() - small.size() + 1; i++){
        if (isSubstringAtLocation(big, small, i)){
            result.push_back(i);
        }
    }
    return result;
}

unordered_map<string, vector<int>> searchAll(string big, vector<string> smalls){
    unordered_map<string, vector<int>> res;
    for (auto small : smalls){
        vector<int> locations = search(big, small);
        res[small] = locations;
    }
    return res;
}

int main()
{
    vector<string> test = {"is", "ppi", "hi", "sis", "i", "ssippi"};
    string big = "mississippi";

    unordered_map<string, vector<int>> res = searchAll(big, test);
    for (auto s : res){
        cout << s.first << ": ";
        for (auto i : s.second){
            cout << i << ", ";
        }
        cout << endl;
    }
    return 0;
}
