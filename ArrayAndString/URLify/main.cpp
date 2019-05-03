#include <iostream>

using namespace std;

string URLify(string s, int length){
    string resultString = "";
    for (int i = 0; i < length; i++){
        if(s.at(i) != ' ')
            resultString += s.at(i);
        else
            resultString += "%20";
    }
    return resultString;
}

int main()
{
    string testString = "Mr John   Snow      ";
    string result = URLify(testString, 14);
    cout << result << endl;
}
