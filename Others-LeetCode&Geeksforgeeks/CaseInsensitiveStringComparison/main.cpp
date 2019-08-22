#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

// C++ 11 Approach1: Using transfrom to all lowercase

int caseInsensitiveMatch(string s1, string s2){
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    if (s1.compare(s2) == 0) {
        return 1;
    }
    return 0;
}

// C++ 11 Approach2: equal() with self-define compare function or lambda function

bool caseInsensitiveMatchCpp11(string &s1, string &s2){
    return ((s1.size() == s2.size()) && (equal(s1.begin(), s1.end(), s2.begin(), [](char &c1, char & c2){
        return ((c1 == c2) || (::toupper(c1) == ::toupper(c2)));})));
}

// C++ Approcah3: isequal()
// returns true if both strings are equal in case insensitive manner


int main()
{
    string s1, s2;
    s1 = "Hello World";
    s2 = "HEllO WORld";
    if (caseInsensitiveMatch(s1, s2)){
        cout << "Strings are same" << endl;
    } else {
        cout << "STrings are not same" << endl;
    }

    if (caseInsensitiveMatchCpp11(s1, s2)){
        cout << "Strings are same" << endl;
    } else {
        cout << "STrings are not same" << endl;
    }

    return 0;
}
