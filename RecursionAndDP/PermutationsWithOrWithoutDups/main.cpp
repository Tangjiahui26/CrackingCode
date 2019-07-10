#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// without duplicates

vector<string> getPermutations(string str){
    vector<string> permutations;

    if (str.empty()){
        permutations.push_back(str);
        return permutations;
    }

    char last_char = str.back();
    str.pop_back();

    for (const string & permutation : getPermutations(str)){
        for (size_t i = 0; i <= permutation.length(); i++){
            string permutation_copy = permutation;
            permutation_copy.insert(i, 1, last_char);
            permutations.push_back(permutation_copy);
        }
    }

    return permutations;
}

// without duplicates -> STL form GEEKFORGEEKS

void permute(string s, string out){
    // base case
    if (s.size() == 0) {
        cout << out << endl;
    }

    for (size_t i = 0; i < s.size(); i++){
        // remove first character from s and add it to out
        permute(s.substr(1), out + s[0]);

        // rotate string in a way second character moves to the beginning
        rotate(s.begin(), s.begin() + 1, s.end());
    }
}

// with duplicates -> no duplicates in output permutations from GEEKFORGEEKS

bool shouldSwap(char str[], int start, int curr){
    for (int i = start; i < curr; i++){
        if(str[i] == str[curr]){
            return 0;
        }
    }
    return 1;
}

// print all distinct permutations in str[0..n+1]
void findPermutations(char str[], int index, int n){
    if (index >= n) {
        cout << str << endl;
        return;
    }

    for (int i = index; i < n; i++){
        bool check = shouldSwap(str, index, i);
        if (check) {
            swap(str[index], str[i]);
            findPermutations(str, index+1, n);
            swap(str[index], str[i]);
        }
    }
}

int main()
{

    // test1
//    string test = "abc";
//    for(const string& str : getPermutations(test)) {
//        cout << str << endl;
//    }

//    permute(test, "");

    // test2 - duplicates
    char str[] = "abca";
    int n = strlen(str);
    findPermutations(str, 0, n);

    return 0;
}
