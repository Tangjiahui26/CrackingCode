#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// runtime requirement O(n)
// space O(1)

int getMajority(vector<int>& arr){
    int majority = 0;
    int count = 0;
    for (auto v : arr){
        if (count == 0){
            majority = v;
        }

        if (majority == v){
            count++;
        } else {
            count--;
        }
    }
    return majority;
}

bool validate(vector<int>& arr, int k){
    int count = 0;
    for (auto v : arr){
        if (v == k){
            count++;
        }
    }
    return count > static_cast<int>(arr.size() / 2);
}

int findMajorityElement(vector<int> arr){
    int m = getMajority(arr);
    return validate(arr, m) ? m : -1;
}

int main()
{
    vector<int> test = {7, 1, 3, 7, 3 ,7 ,1, 7 ,7};
    cout << findMajorityElement(test) << endl;
    return 0;
}
