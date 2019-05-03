#include <iostream>

using namespace std;

string stringCaseSwitch(string s){
    for (size_t i = 0; i < s.length(); i++){
        if (s.at(i) >= 'A' && s.at(i) <= 'Z')
            s.at(i) += 32;
    }
    return s;
}

bool checkPalindromePermutation(string s){
    s = stringCaseSwitch(s);
    int counter[128] = {0};
    int realLength = 0;
    for (size_t i = 0; i < s.length(); i++){
        if (s.at(i) != ' '){
            int count = s.at(i) - 'a' + 61;
            counter[count]++;
            realLength++;
        }
    }

    int sum = 0;
    for (size_t i = 0; i < 128; i++){
        counter[i] %=2;
        sum +=counter[i];
    }

    if(realLength % 2 == 0){
        return sum == 0;
    } else {
        return sum == 1;
    }
}

int main()
{
    string testString = "a Aa";
    string result = checkPalindromePermutation(testString) ? "TURE":"FALSE";
    cout << "Check Palindrome Permutation: " << result << endl;
    return 0;
}
