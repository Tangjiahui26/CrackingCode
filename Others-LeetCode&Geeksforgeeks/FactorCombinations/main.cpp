#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Write a program to print all the combinations of factors of given number n.

// solution: take one array or array of integers or list of list of integers
// to store all the factors combination possible for the given n.

// recursively
// first is current factor to be considered

void factorsFunc(int first, int each_product, int n, vector<vector<int>>& ret, vector<int> cur){
    if (each_product == n){
        if (!cur.empty()) {
            ret.push_back(cur);
        }
    }else if (each_product < n && first < n){
        for (int i = first; i < n; ++i){
            if (each_product * i > n){
                break;
            }

            if (n % i != 0){
                continue;
            }

            cur.push_back(i);
            factorsFunc(i, each_product*i, n, ret, cur);
            cur.pop_back();
        }
    }
}


vector<vector<int>> getFactors(int n){
    vector<vector<int>> ret;
    vector<int> cur;
    factorsFunc(2, 1, n, ret, cur);
    return ret;
}

// lambda function implementation

vector<vector<int>> factorsComb(int n){
    vector<vector<int>> ret = {};

    function<void(int, vector<int>&)> factors = [&](int num, vector<int>& cur){
        int last = cur.empty() ? 2 : cur.back();
        for (int f = last; f < num; ++f){
            if (num % f != 0){
                continue;
            }
            cur.push_back(f);
            factors(num / f, cur);
            cur.pop_back();
        }

        if (!cur.empty() && num >= last){
            cur.push_back(num);
            ret.push_back(cur);
            cur.pop_back();
        }
    };

    vector<int> cur = {};
    factors(n, cur);
    return ret;
}

int main()
{
    int n = 16;
    vector<vector<int>> result = getFactors(n);
    for (auto vec : result){
        for (auto factor : vec){
            cout << factor << " ";
        }
        cout <<endl;
    }

    vector<vector<int>> result2 = factorsComb(n);
    for (auto vec : result2){
        for (auto factor : vec){
            cout << factor << " ";
        }
        cout <<endl;
    }
    return 0;
}
