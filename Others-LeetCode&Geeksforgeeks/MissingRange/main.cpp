#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// Question: Given an sorted integer array where the range of elements are [0, 99] inclusive,
// return its missing ranges.

// For example, given [0, 1, 3, 50, 75], return ["2", "4->49", "51->74", "76->99"]

using namespace std;


// added two artificial elements: -1 and 100
vector<string> missingRange(vector<int> a, int start, int end){
    vector<string> res;
    int prev = start - 1;

    for (int i = 0; i <= a.size(); i++){
        int curr = (i == a.size() ? end + 1 :  a[i]);
        if (curr - prev >= 2){
            if (prev + 1 == curr -1){
                res.push_back(to_string(prev + 1));
            } else {
                res.push_back(to_string(prev + 1) + "->" + to_string(curr - 1));
            }
        }
        prev = curr;
    }
    return res;
}

void display(vector<string>& ret){
    for (int i = 0; i < ret.size(); i++){
        cout << ret[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> a = {1};
    vector<string> ret = missingRange(a, 0, 99);
    display(ret);

    vector<int> b = {6};
    ret = missingRange(b, 0, 99);
    display(ret);

    vector<int> c = {0, 1, 3, 50, 75};
    ret = missingRange(c, 0, 99);
    display(ret);

    vector<int> d = {};
    ret = missingRange(d, 0, 99);
    display(ret);

    return 0;
}
