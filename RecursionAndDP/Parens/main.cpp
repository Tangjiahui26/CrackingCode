#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void parens(vector<string> & list, int leftRem, int rightRem, char str[], int index){
    if (leftRem < 0 || rightRem < leftRem){
        //invalid
        return;
    }

    if (leftRem == 0 && rightRem == 0){
        string myString(str);
        list.push_back(myString);
    } else {
        str[index] = '(';
        // add left and recurse
        parens(list, leftRem - 1, rightRem, str, index + 1);

        str[index] = ')';
        // add right and recurse
        parens(list, leftRem, rightRem - 1, str, index + 1);
    }
}

vector<string> getParens(int count){
    char str[count * 2];
    vector<string> list;
    parens(list, count, count, str, 0);
    return list;
}

int main()
{
    vector<string> result = getParens(3);
    for (const string & str : result){
        cout << str << endl;
    }
    return 0;
}
