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

    for (const string& permutation : getPermutations(str)){
        for (size_t i = 0; i <= permutation.length(); i++){
            string permutation_copy = permutation;
            permutation_copy.insert(i, 1, last_char);
            permutations.push_back(permutation_copy);
        }
    }

    return permutations;
}

// with duplicates -> no duplicates in output permutations

int main()
{
    string test = "abc";
    for(const string& str : getPermutations(test)) {
        cout << str << endl;
    }
    return 0;
}
