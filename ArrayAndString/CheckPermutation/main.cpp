#include <iostream>

using namespace std;

bool checkPermutation(string s1, string s2){
    if (s1.length() != s2.length())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for(size_t i = 0; i < s1.length(); i++){
        if(s1.at(i) != s2.at(i))
            return false;
    }
    return true;
}

int main()
{
    string stringTest1 = " abcd98i+";
    string stringTest2 = "cbda 89+i";
    string result = checkPermutation(stringTest1, stringTest2) ? "TURE":"FALSE";
    cout << "Check Permutation: " << result << endl;
    return 0;
}
