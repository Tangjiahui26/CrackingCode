#include <iostream>

using namespace std;

int findMaxDepth(string str){
    int current_max = 0; // current count
    int max = 0;
    int n = str.length();

    for (int i = 0; i < n; i++){
        if (str[i] == '('){
            current_max++;
            if (current_max > max){
                max = current_max;
            }
        } else if (str[i] == ')'){
            if (current_max > 0){
                current_max--;
            } else {
                return -1;
            }
        }
    }

    if (current_max != 0){
        return -1;
    }

    return max;
}

int main()
{
    string s1 = "b)(c)()";
    cout << findMaxDepth(s1) << endl;

    string s2 = "";
    cout << findMaxDepth(s2) << endl;

    string s3 = "(((X))(((Y))))";
    cout << findMaxDepth(s3) << endl;

    return 0;
}
