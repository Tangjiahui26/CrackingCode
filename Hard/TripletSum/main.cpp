#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

pair<tuple<int, int, int>, int> tripleSum(vector<int>& arr, int x){
    sort(arr.begin(), arr.end());
    int closestNum = INT_MAX;
    tuple<int, int, int> res(0, 0, 0);

    if (arr.size() <= 3){
        return make_pair(res, 0);
    }

    for (int i = 0; i < arr.size() - 2; i++){
        int ptr1 = i + 1;
        int ptr2 = arr.size() - 1;

        while (ptr1 < ptr2){
            int sum = arr[i] + arr[ptr1] + arr[ptr2];

            if (abs(x - sum) < abs(x - closestNum)){
                get<0>(res) = arr[i];
                get<1>(res) = arr[ptr1];
                get<2>(res) = arr[ptr2];
                closestNum = sum;
            }

            if (sum > x){
                ptr2--;
            } else {
                ptr1++;
            }
        }
    }
    return make_pair(res, closestNum);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, -5};
    int x = 10;
    pair<tuple<int, int, int>, int> res = tripleSum(arr, x);
    cout << "Closest Sum is " << res.second << endl;
    cout << "Triplet is " << get<0>(res.first) << ", " << get<1>(res.first) << ", " << get<2>(res.first) << endl;
    return 0;
}
