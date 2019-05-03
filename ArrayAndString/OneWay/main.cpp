#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <cctype>

using namespace std;

string caseChangeAndWhitespaceDeletion(string s){
    string result = "";
    for(size_t i = 0; i < s.length(); i++){
    }
    cout << s << endl;
    return result;
}


bool checkOneWay(string s1, string s2){
    if (abs(int (s1.length() - s2.length())) >= 2){
        return 0;
    }
}

int main()
{
    string stringTest1 = "        bcd98i+";
    string stringTest2 = "cbda 89+i";
    caseChangeAndWhitespaceDeletion(stringTest1);
//    string result = checkOneWay(stringTest1, stringTest2) ? "TURE":"FALSE";
//    cout << "Check OneWay: " << result << endl;
    return 0;
}
