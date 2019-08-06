#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

// since this question is more JAVA-specific, so here I give the solutions for another similar encoding
// question: LeetCode (271). Encode and Decode strings

string encode(vector<string> & strs){
    stringstream ss;
    for (auto & s : strs){
        ss << s.size() << "|" << s << "|";
    }
    return ss.str();
}

vector<string> decode(string s){
    vector<string> res;
    auto len = 0;
    string str;
    enum Mode {LEN, STR} mode = LEN;
    for (auto ch: s){
        switch (mode) {
        case LEN:
            if (ch != '|') {
                len = 10*len + ch - '0';
            } else {
                mode = STR;
                str = "";
            }
            break;
        case STR:
            if (len-- > 0){
                str.push_back(ch);
            } else {
                res.push_back(str);
                len = 0;
                mode = LEN;
            }
            break;
        }
    }
    return res;
}

int main()
{
    vector<string> test = {"test1", "test2", "test3", "testtest"};
    cout << encode(test) << endl;
    vector<string> result = decode(encode(test));
    for (auto s : result){
        cout << s << endl;
    }
    return 0;
}
