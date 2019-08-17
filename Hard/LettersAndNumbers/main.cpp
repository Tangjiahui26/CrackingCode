#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

// brute force

bool hasEqualLettersAndNumbers(vector<char> arr, int start, int end){
    int counter = 0;
    for (int i = start; i <= end; i++){
        if(isalpha(arr[i])) {
            counter++;
        } else if (isdigit(arr[i])){
            counter--;
        }
    }
    return counter == 0;
}

// or we can simply slice the vector
vector<char> extract(vector<char>& arr, int start, int end){
    vector<char> res(end - start + 1);
    for (int i = start; i <= end; i++){
        res[i - start] = arr[i];
    }
    return res;
}

vector<char> findLongestSubArray(vector<char>& arr){
    for (int len = arr.size(); len > 1; len--){
        for (int i = 0; i <= arr.size() - len; i++){
            if (hasEqualLettersAndNumbers(arr, i, i + len - 1)) {
                return extract(arr, i, i + len - 1);
            }
        }
    }
    return {};
}

// optimal
// compute the deltas between count of numbers and count of letters
// then find pair in deltas with matching values and largest span

vector<int> computeDeltaArray(vector<char>& arr){
    vector<int> res(arr.size());
    int delta = 0;
    for (int i = 0; i < arr.size(); i++){
        if(isalpha(arr[i])) {
            delta++;
        } else if (isdigit(arr[i])){
            delta--;
        }
        res[i] = delta;
    }
    return res;
}

vector<int> findLongestMatch(vector<int>& deltas){
    unordered_map<int, int> m;
    vector<int> maxL(2);
    m.insert({0, -1});
    for (int i = 0; i < deltas.size(); i++){
        if (m.find(deltas[i]) == m.end()){
            m.insert({deltas[i], i});
        } else {
            int match = m.find(deltas[i])->first;
            int dis = i - match;
            int longest = maxL[1] - maxL[0];
            if (dis > longest){
                maxL[1] = i;
                maxL[0] = match;
            }
         }
    }
    return maxL;
}

vector<char> findLongestSubarray(vector<char>& arr){
    vector<int> deltas = computeDeltaArray(arr);
    vector<int> match = findLongestMatch(deltas);

    return extract(arr, match[0] + 1, match[1]);
}

int main()
{
    vector<char> test = {'a', 'a', 'a', 'a', '1', '1', 'a', '1', '1', 'a', 'a', '1', 'a', 'a', '1', 'a', 'a', 'a', 'a', 'a'};
    vector<char> test2 = {'a', '1', 'a', 'a', 'a', '1', 'a', '1', '1', 'a', '1', 'a'};
    vector<char> test3 = {'a', '1', '1', 'a', '1', 'a'};

    vector<char> res = findLongestSubArray(test3);
    for (auto r : res){
        cout << r << " ";
    }
    cout << endl;
    return 0;
}
