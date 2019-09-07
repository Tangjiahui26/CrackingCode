#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool canBuildWord(string s, bool isOriginalWord, unordered_map<string, bool>& m){
    if (m.find(s) != m.end() && !isOriginalWord){
        return m.at(s);
    }

    for (int i = 1; i < s.size(); i++){
        string left = s.substr(0, i);
        string right = s.substr(i, s.size() - i);
        if ((m.find(left) != m.end())
                && (m.at(left) == true)
                && (canBuildWord(right, false, m))){
            return true;
        }
    }
    m[s] = false;
    return false;
}

string printLongestWord(vector<string>& arr){
    unordered_map<string, bool> m;
    for (auto s : arr){
        m[s]  = true;
    }

    // sort the string array by length
    sort(arr.begin(), arr.end(), [](string &s1, string &s2){
        return s1.size() > s2.size();
    });

    for (auto s : arr){
        if (canBuildWord(s, true, m)){
            return s;
        }
    }
    return "";
}

// Here, we also want to solve some other problems related with Word (String)
// Problem 1: find smallest and largest word in a string

void minMaxLengthWords(string input, string &minWord, string &maxWord){
    int len = input.length();
    int start_index = 0, end_index = 0;
    int min_length = len, min_start_index = 0, max_length = 0, max_start_index = 0;

    while (end_index <= len){
        if (end_index < len && input[end_index] != ' '){
            end_index++;
        } else {
            int curr_length = end_index - start_index;
            if (curr_length < min_length){
                min_length = curr_length;
                min_start_index = start_index;
            }

            if (curr_length > max_length){
                max_length = curr_length;
                max_start_index = start_index;
            }
            end_index++;
            start_index = end_index;
        }
    }

    minWord = input.substr(min_start_index, min_length);
    maxWord = input.substr(max_start_index, max_length);
}

// problem 2: Longest Word in a Dictionary
// Given a list of string words representing an English Dictionary, find
// the longest word in words that can be built one character at a time by
// other words in words. If there is more than one possible answer, return
// the longest word with the smallest lexicographical order.

// solutions: 1. brute force 2. Trie (Prefix tree)

string longestWord(vector<string>& words){
    string best;
    unordered_set<string> dict(words.begin(), words.end());

    for (auto word: words){
        if (word.length() < best.length() || (word.length() == best.length() && word > best)){
            continue;
        }

        string prefix;
        // pruning
        bool valid = true;

        for (int i = 0; i < word.length() - 1 && valid; ++i){
            prefix += word[i];
            if (!dict.count(prefix)){
                valid = false;
            }
        }
        if (valid){
            best = word;
        }
    }
    return best;
}

// Trie class
class Trie{
public:
    Trie() : root_(new TrieNode()){}

    // insert a word into trie
    void insert(const string& word){
        TrieNode* p = root_.get();
        for (const char c : word){
            if (!p->children[c-'a']){
                p->children[c-'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->is_word = true;
    }

    // check if a word is valid or not
    bool hasAllprefixes(const string& word){
        const TrieNode* p = root_.get();
        for (const char c: word){
            if (!p->children[c - 'a']) return false;
            p = p->children[c - 'a'];
            if (!p->is_word) return false;
        }
        return true;
    }

private:
    struct TrieNode{
       TrieNode(): is_word(false), children(26, nullptr){}
       ~TrieNode(){
       for (auto node : children){
            delete node;
            }
        }
        bool is_word;
        vector<TrieNode*> children;
    };

    std::unique_ptr<TrieNode> root_;
};

string longestWordTrie(vector<string>& words){
    // sort words
    sort(words.begin(), words.end(), [](const string& w1, const string& w2){
        if (w1.length() != w2.length()) {
            return w1.length() > w2.length();
        }
        return w1 < w2;
    });

    Trie t;
    for (const string& word : words){
        t.insert(word);
    }

    for (const string& word : words){
        if (t.hasAllprefixes(word)) return word;
    }

    return "";
}

int main()
{
    vector<string> arr = {"test", "code", "testcode", "testcodetestcode"};
    cout << printLongestWord(arr) << endl;

    string test = "Testcode for findlongestWord and smallestWord";
    string minWord, maxWord;
    minMaxLengthWords(test, minWord, maxWord);
    cout << minWord << " " << maxWord << endl;

    vector<string> arr1 = {"t", "code", "te", "tes", "test"};
    cout << longestWord(arr1) << endl;
    cout << longestWordTrie( arr1) << endl;
    return 0;
}
