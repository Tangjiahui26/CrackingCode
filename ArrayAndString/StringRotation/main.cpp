#include <iostream>

using namespace std;

bool isSubString(string s1, string s2) {
    int M = s1.length();
    int N = s2.length();

    for (int i = 0; i <= N-M; i++) {
        int j;
        for (j = 0; j < M; j++) {
            if (s2[i + j] != s1[j])
                break;
        }
        if (j == M)
            return true;
    }
    return false;
}

bool isRotation(string s1, string s2) {
    int length1 = s1.length();
    int length2 = s2.length();
    if (length1 == length2 && length1 > 0) {
        string s1s1 = s1 + s1;
        return isSubString(s2, s1s1);
    }
    return false;
}

int main()
{
    string stringTest1 = "iceappleju";
    string stringTest2 = "applejuice";
    string result = isRotation(stringTest1, stringTest2) ? "TURE":"FALSE";
    cout << "Check isRotation: " << result << endl;
    return 0;
}
