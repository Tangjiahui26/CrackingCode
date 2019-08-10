#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// solution 1 (Most optimal): word lookup:
// create a hash table that maps from a sequence of digits to a list of strings
// Go through each word in the dictionary and convert it to its T9 representation, then store each of these
// look up the entry in the hash table: dictionary.get(numbers) (JAVA) find (C++)

// solution 2 (optimzed): trie (dictionary tree) provided by JAVA to help termianl (stop recursing) with some prefix

// solution 3 (brute force)
// assume that we have a dictionary  (wordlist) here called unordered_set<string> wordList

vector<vector<char>> t9Letters{{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'},
                                {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                                {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

vector<char> getT9Chars(char digits){
    if (!isdigit(digits)){
        throw "Not digits!";
        return {};
    }
    int dig = digits - '0';
    return t9Letters[dig];
}


void getWords(string number, size_t size, size_t index, string prefix, set<string>& wordList, vector<string>& results){
    if (index == size && wordList.find(prefix) != wordList.end()){
        results.push_back(prefix);
        return;
    } else if (index >= size){
        return;
    }

    char digit = number.at(index);
    vector<char> letters = getT9Chars(digit);

    if (!letters.empty()){
        for (auto l : letters){
            getWords(number, number.size(), index + 1, prefix + l, wordList, results);
        }
    }
}

vector<string> getT9Words(string number, set<string>& wordList){
    vector<string> results;
    getWords(number, number.size(), 0, "", wordList, results);
    return results;
}

int main()
{
    set<string> wordList = {"tree", "used"};
    string number = "8733";
    vector<string> results = getT9Words(number, wordList);
    for (auto r : results){
        cout << r << endl;
    }

    return 0;
}
