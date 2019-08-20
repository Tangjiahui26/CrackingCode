#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// from Youtube @Bo Qian

// Dynamic Programming - LIS

// here is the basic implementation of the code
/*
 * Problem: For a vector D of size n, find its LIS
 *
 * Define vector L:
 * L[i] -> A vector, LIS of D that ends with D[i]
 * L[0] = {D[0]}
 *
 * L[i] = longest(L[j] | j<i, D[j]<D[i]) + "D[i]"
 *
 * Example: {3, 2, 6, 4, 5, 1}
 *
 * L[0]: 3
 * L[1]: 2
 * L[2]: 2, 6
 * L[3]: 2, 4
 * L[4]: 2, 4, 5
 * L[5]: 1
 */
vector<vector<int>> calc_LIS(vector<int>& D){
    vector<vector<int>> L(D.size());
    L[0].push_back(D[0]);

    for (int i = 1; i<D.size(); i++){
        for (int j = 0; j <i; j++){
            if ((D[i] > D[j]) && (L[i].size() < L[j].size())){
                L[i] = L[j];
            }
        }
        L[i].push_back(D[i]);
    }
    return L;
}

int main()
{
    vector<int> arr = {3, 2, 6, 4, 5 ,1};
    vector<vector<int>> res = calc_LIS(arr);
    for (auto a : res){
        for (auto v : a){
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
