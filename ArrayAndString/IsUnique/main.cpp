#include <iostream>

using namespace std;

bool isUniqueUsingSorting(string s){
    if (s.empty()){
        return true;
    }

    sort(s.begin(), s.end());
    for (size_t i = 0; i < s.length() - 1; i++) {
        if (s.at(i) == s.at(i + 1)){
            return false;
        }
    }
    return true;
}

bool isUniqueUsingFlag(string s){
    // Assume it is ASCII
    if (s.length() > 128){
        return false;
    }

    //Build bit vector to store flags
    int checker = 0;
    for (size_t i = 0; i < s.length(); i++) {
        int ch = s.at(i) - 'a' + 61;
        if ((checker & (1 << ch)) > 0){
            return false;
        }
        checker |= (1 << ch);
    }
    return true;
}

int main()
{
    string stringTest = "cbda 89+i";
    string result = isUniqueUsingFlag(stringTest) ? "TURE":"FALSE";
    cout << "Is Unique: " << result << endl;
    return 0;
}
