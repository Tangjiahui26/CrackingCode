#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// brute force: runtine o(n^4)

string buildFromPattern(string pattern, string main, string alt){
    string res;
    char first = pattern.front();
    for (char& c : pattern){
        if (c == first){
            res.append(main);
        } else {
            res.append(alt);
        }
    }
    return res;
}

bool patternMatchingBF(string pattern, string value){
    if (pattern.length() == 0){
        return value.length() == 0;
    }

    int size = value.length();
    for (int mainSize = 0; mainSize < size; mainSize++){
        string main = value.substr(0, mainSize + 1);
        for (int altStart = mainSize; altStart <= size; altStart++){
            for (int altEnd = altStart; altEnd <= size; altEnd++){
                // note: substr in C++ sub(size_t pos, size_t, len)
                string alt = value.substr(altStart, altEnd - altStart + 1);
                string comb = buildFromPattern(pattern, main, alt);
                if (comb.compare(value) == 0){
                    return true;
                }
            }
        }
    }
    return false;
}

// Optimized: on the alternate string
// runtime: O(n^2)

int countOf(string pattern, char c){
    int count = 0;
    for (size_t i = 0; i < pattern.length(); i++){
        if (c == pattern.at(i)){
            count++;
        }
    }
    return count;
}

bool patternMatchingOptimized(string pattern, string value){
    if (pattern.length() == 0){
        return value.length() == 0;
    }

    char mainChar = pattern.front();
    char altChar = mainChar == 'a' ? 'b' : 'a';
    int size = value.length();

    int countOfMain = countOf(pattern, mainChar);
    int countOfAlt = pattern.length() - countOfMain;
    size_t firstAlt = pattern.find(altChar);
    int maxMainSize = size / countOfMain;

    for (int mainSize = 0; mainSize <= maxMainSize; mainSize++){
        int remainLength = size - mainSize * countOfMain;
        string first = value.substr(0, mainSize + 1);
        // check if countOfAlt is zero or Alter size is zero
        if (countOfAlt == 0 || remainLength % countOfAlt == 0) {
            int altIndex = firstAlt * mainSize;
            int altSize = countOfAlt == 0 ? 0 : remainLength / countOfAlt;
            string second =  countOfAlt == 0 ? "" : value.substr(altIndex, altSize + 1);
            string comb = buildFromPattern(pattern, first, second);
            if (comb.compare(value) == 0){
                return true;
            }
        }
    }
    return false;
}

//int main()
//{
//    string patternTest = "aabba";
//    string valueTest = "catcatdogdogcat";
//    string r = patternMatchingBF(patternTest, valueTest) ? "Matched" : "Don't Match";
//    string r_optimized = patternMatchingBF(patternTest, valueTest) ? "Matched" : "Don't Match";
//    cout << r << endl;
//    cout << r_optimized << endl;
//    return 0;
//}

// a similar question: wildcard pattern matching

/***
 The wildcard pattern can include the characters ‘?’ and ‘*’
 ‘?’ – matches any single character
 ‘*’ – Matches any sequence of characters (including the empty sequence)
 from geeksforgeeks

 both text and pattern are null
 T[0][0] = true;

 pattern is null
 T[i][0] = false;

 text is null
 T[0][j] = T[0][j - 1] if pattern[j – 1] is '*'

DP relation :

 If current characters match, result is same as
 result for lengths minus one. Characters match
 in two cases:
 a) If pattern character is '?' then it matches
    with any character of text.
 b) If current characters in both match
if ( pattern[j – 1] == ‘?’) ||
     (pattern[j – 1] == text[i - 1])
    T[i][j] = T[i-1][j-1]

 If we encounter ‘*’, two choices are possible-
 a) We ignore ‘*’ character and move to next
    character in the pattern, i.e., ‘*’
    indicates an empty sequence.
 b) '*' character matches with ith character in
     input
else if (pattern[j – 1] == ‘*’)
    T[i][j] = T[i][j-1] || T[i-1][j]

else // if (pattern[j – 1] != text[i - 1])
    T[i][j]  = false
    ***/

// since we need a 2D lookup table so here we use char array with size

// Dynamic Programming
bool wildcardPatternMatching(char str[], char pattern[], int n, int m){
    if (m == 0){
        return n == 0;
    }

    bool lookup[n+1][m+1];
    memset(lookup, false, sizeof(lookup));
    lookup[0][0] = true;

    // Only '*' can match with empty string
    for (int j = 1; j <= m; j++) {
        if (pattern[j - 1] == '*') {
            lookup[0][j] = lookup[0][j - 1];
        }
    }

    // bottom-up DP
    for (int i = 0; i <=n; i++){
        for (int j = 0; j <= m; j++){
            if (pattern[j - 1] == '*'){
                lookup[i][j] = lookup[i][j - 1] || lookup[i -1][j];
            } else if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1]){
                lookup[i][j] = lookup[i - 1][j - 1];
            } else {
                lookup[i][j] = false;
            }
        }
    }
    return lookup[n][m];
}

int main(){
    char str[] = "baaabab";
    char pattern[] = "*****ba*****ab";
    if (wildcardPatternMatching(str, pattern, strlen(str), strlen(pattern)))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    return 0;
}
