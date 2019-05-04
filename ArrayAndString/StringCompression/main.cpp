#include <iostream>
#include <map>

using namespace std;

string stringCompression(string s) {
    string result = "";
    map<char, int> m;
    for (size_t i = 0; i < s.length(); i++) {
        if (s.at(i) != ' ') {
            m[s.at(i)]++;
        }
    }
    map<char, int>::iterator i;
    for (i = m.begin(); i != m.end(); i++) {
        result += i->first;
        result += to_string(i->second);
    }

    if(s.length() < result.length()) {
        return s;
    } else {
        return result;
    }
}

int main()
{
    string testString = "aASSS   SSSSSbc";
    string resultString = stringCompression(testString);
    cout << "Original String: " << testString << endl;
    cout << "String After Compression: " << resultString << endl;
    return 0;
}
