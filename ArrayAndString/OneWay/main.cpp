#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <cctype>

using namespace std;

bool checkForAdditionOrRemove(string s1, string s2);
bool checkForReplace(string s1, string s2);

string caseChangeAndWhitespaceDeletion(string s){
    string result = "";
    for(size_t i = 0; i < s.length(); i++){
        if(s.at(i) != ' ') {
            if (s.at(i) >= 'A' && s.at(i) <= 'Z') {
                s.at(i) += 32;
            }
            result = result + s.at(i);
        }
    }
    return result;
}


bool checkOneWay(string s1, string s2){
    string string1 = caseChangeAndWhitespaceDeletion(s1);
    string string2 = caseChangeAndWhitespaceDeletion(s2);
    if (abs(int (string1.length() - string2.length())) >= 2){
        return false;
    } else if (abs(int (string1.length() - string2.length())) == 1) {
        return checkForAdditionOrRemove(string1, string2);
    } else {
        return checkForReplace(string1, string2);
    }
    return true;
}

bool checkForReplace(string s1, string s2){
    bool difference = false;
    for (size_t i = 0; i < s1.length(); i++){
        if (s1.at(i) != s2.at(i)) {
            if (difference) {
                return false;
            }
            difference = true;
        }
    }
    return true;
}

bool checkForAdditionOrRemove(string s1, string s2) {
    int counter1[128] = {0};
    int counter2[128] = {0};
    for (size_t i = 0; i < s1.length(); i++) {
        int count1 = s1.at(i) - 'a' + 61;
        counter1[count1]++;
    }

    for (size_t i = 0; i < s2.length(); i++) {
        int count2 = s2.at(i) - 'a' + 61;
        counter2[count2]++;
    }

    int sum = 0;
    for (int i = 0; i < 128; i++) {
        sum += abs(counter1[i] - counter2[i]);
    }

    if(sum == 1)
        return true;
    else
        return false;
}

int main()
{
    string stringTest1 = "pal+e";
    string stringTest2 = "pal+e++";
    string result = checkOneWay(stringTest1, stringTest2) ? "TURE":"FALSE";
    cout << "Check OneWay: " << result << endl;
    return 0;
}
