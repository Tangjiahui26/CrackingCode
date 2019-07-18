#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

bool stringToBool(string c){
    return c.compare("1") == 0 ? true : false;
}

int countEval(string s, bool result, map<string, int>& memo){
    if (s.length() == 0){
        return 0;
    }
    if (s.length() == 1){
        return stringToBool(s) == result ? 1 : 0;
    }
    // memoization
    if (memo.find(to_string(result) + s) != memo.end()) {
        return memo[to_string(result) + s];
    }

    int ways = 0;

    for (size_t i = 1; i < s.length(); i += 2){
        char c = s.at(i);
        string left = s.substr(0, i);
        string right = s.substr(i + 1, s.length() - i - 1);
        int leftTrue = countEval(left, true, memo);
        int leftFalse = countEval(left, false, memo);
        int rightTrue = countEval(right, true, memo);
        int rightFalse = countEval(right, false, memo);
        int total = (leftTrue + leftFalse) * (rightTrue + rightFalse);

        int totalTrue = 0;
        if (c == '^') {
            totalTrue = leftTrue * rightFalse + leftFalse * rightTrue;
        } else if (c == '&') {
            totalTrue = leftTrue * rightTrue;
        } else if (c == '|') {
            totalTrue = leftTrue * rightTrue + leftFalse * rightTrue | leftTrue * rightFalse;
        }
        int subWays = result ? totalTrue : total - totalTrue;
        ways += subWays;
    }
    memo[to_string(result) + s] = ways;
    return ways;
}

int main()
{
    string test = "1^0|0|1"; // 2
//    string test2 = "0&0&0&1^1|0"; // 10
    map<string, int> memo;
    cout << countEval(test, false, memo) << endl;
    return 0;
}
