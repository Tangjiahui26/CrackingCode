#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// naive solution: iterating the word list and update the min distance

int wordDistance(vector<string>& words, string word1, string word2){
    int n = words.size(), idx1 = -1, idx2 = -1, distance = INT_MAX;
    for (int i = 0; i < n; i++){
        if (words[i] == word1){
            idx1 = i;
        } else if (words[i] == word2){
            idx2 = i;
        }

        if (idx1 != -1 && idx2 != -1){
            distance = min(distance, abs(idx1 - idx2));
        }
    }
    return distance;
}

// Follow-up: how would you optimize the code so that it can be called repeatedly?

// create a wordDistance class
class WordDistance{
public:
    WordDistance(vector<string> words){
        int n = words.size();
        for (int i = 0; i < n; i++){
            wordInd[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2){
        vector<int> indice1 = wordInd[word1];
        vector<int> indice2 = wordInd[word2];
        int m = indice1.size(), n = indice2.size();
        int i = 0, j = 0, distance = INT_MAX;

        while(i < m && j < n){
            distance = min(distance, abs(indice1[i] - indice2[j]));
            if (indice1[i] < indice2[j]){
                i++;
            } else {
                j++;
            }
        }
        return distance;
    }

   private:
    unordered_map<string, vector<int>> wordInd;
};

// What if the two words can be the same?

int shortestWordDistance(vector<string>& words, string word1, string word2){
    int n = words.size(), idx1 = -1, idx2 = -1, distance = INT_MAX;
    for (int i = 0; i < n; i++){
        if (word1 == word2){
            if (words[i] == word1){
                if (idx1 > idx2) {
                    idx2 = i;
                } else{
                    idx1 = i;
                }
            }
        } else {
            if (words[i] == word1){
                idx1 = i;
            } else if (words[i] == word2){
                idx2 = i;
            }
        }
        if (idx1 != -1 && idx2 != -1){
            distance = min(distance, abs(idx1 - idx2));
        }
    }
    return distance;
}

int main()
{
    vector<string> wordList = {"practice", "makes", "perfect", "coding", "makes"};
    string word1 = "makes";
    string word2 = "coding";
    string word3 = "practice";
    cout << wordDistance(wordList, word1, word2) << endl;

    WordDistance wordDistance(wordList);
    cout << wordDistance.shortest(word1, word2) << endl;
    return 0;
}
