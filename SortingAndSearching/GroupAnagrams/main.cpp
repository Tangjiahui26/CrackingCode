#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

// approach 1 : sort all the elements
// @github oskargustafsson

void groupAnagrams(vector<string>& strings) {
    sort(strings.begin(), strings.end(), [](string s0, string s1) {
        sort(s0.begin(), s0.end());
        sort(s1.begin(), s1.end());
        return s0 < s1;
    });
}

// approach 2 : hashtable to count the elements of each array

void groupAnagramsMap(vector<string>& strings){
    map<string, vector<string>> mapList;
    for (string& str : strings){
        string sorted_str = str;
        sort(sorted_str.begin(), sorted_str.end());
        mapList[sorted_str].push_back(str);
    }

    strings.clear();
    // convert has table to array
    for (auto& l : mapList){
        for (string& s : l.second){
            strings.push_back(s);
        }
    }
}

int main()
{
    vector<string> test = { "abcd", "abab", "cbda", "aabb", "dabc", "mmmm"};
    groupAnagramsMap(test);
    for (string& s : test){
        cout << s << endl;
    }
    return 0;
}
