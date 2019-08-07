#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int getcode(char c){
    switch (c) {
    case 'R':
        return 0;
        break;
    case 'Y':
        return 1;
        break;
    case 'G':
        return 2;
        break;
    case 'B':
        return 3;
        break;
    default:
        return -1;
        break;
    }
}

int MAX_COLOURS = 4;

class Result
{
 public:
    int hits = 0;
    int pseudoHits = 0;
    void getResult(){
        cout << "(" << this->hits << ", " << this->pseudoHits << ")" << endl;
    }
};

Result* masterMind(string guess, string solution){
    // if the sizes are not the same, return null
    if (guess.length() != solution.length())
        return nullptr;

    Result* res = new Result();
    // delete?
    int frequences[MAX_COLOURS];

    for (size_t i = 0; i < guess.length(); i++){
        if (guess[i] == solution[i]){
            res->hits++;
        } else {
            int code = getcode(solution[i]);
            frequences[code]++;
        }
    }

    for (size_t i = 0; i < guess.length(); i++){
        int code = getcode(guess[i]);
        // check here: code should not be negative, frequences should be positive
        if (code >= 0 && guess[i] != solution[i] && frequences[code] > 0){
            res->pseudoHits++;
            frequences[code]--;
        }
    }
    return res;
}

int main()
{
    string solution = "RGBY";
    string guess = "GGRR";
    Result* res = masterMind(guess, solution);
    res->getResult();
    return 0;
}
