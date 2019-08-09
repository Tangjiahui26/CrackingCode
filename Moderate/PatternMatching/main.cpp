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

int main()
{
    string patternTest = "aabba";
    string valueTest = "catcatdogdogcat";
    string r = patternMatchingBF(patternTest, valueTest) ? "Matched" : "Don't Match";
    string r_optimized = patternMatchingBF(patternTest, valueTest) ? "Matched" : "Don't Match";
    cout << r << endl;
    cout << r_optimized << endl;
    return 0;
}
