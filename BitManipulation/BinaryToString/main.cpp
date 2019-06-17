#include <iostream>
#include <string>

using namespace std;

string binaryToString(double num){
    if (num >=1 || num <= 0) {
        return "ERROR";
    }

    string result;
    result.push_back('.');
    while (num > 0) {
        if (result.length() >= 32) {
            return "ERROR";
        }

        double r = num * 2;
        if(r >= 1) {
            result.push_back('1');
            num = r - 1;
        } else {
            result.push_back('0');
            num = r;
        }
    }
    return result;
}

int main()
{
    string s = binaryToString(0.6666259765625);
    cout << "Binary Representation: " << s << endl;
    return 0;
}
