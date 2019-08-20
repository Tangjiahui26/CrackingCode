#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// from Youtube @Bo Qian

// here is the details
/*
 * Longest Common Subsequence
 * X = ACCG
 * Y = CCAGCA
 *
 * CS of length1: {A} {C} {G}
 * CS of length2: {AC} {CC} {CG} {AG}
 * CS of length3: {CCG}
 * CS of length4:
 *
 * Define:
 * C[i][j] - length of LCS of sequence X[1...i] and Y[1...j]
 * Thus: C[i][0] == 0 for all i
 *       C[0][j] == 0 for all j
 *
 * Goal: Find C[N][M]
 *
 * C[i][j] = { C[i-1][j-1] + 1, X[i] == Y[j]
 *           { MAX(C[i-1][j], C[i][j-1]), X[i] != Y[i]
 */

void prt_LCS(vector<vector<char>>& S, string& X, int i, int j){
    if (i==0 || j==0){
        return;
    }

    if ('s' == S[i][j]){
        prt_LCS(S, X, i-1, j-1);
        cout << X[i];
    } else if('j' == S[i][j]){
        prt_LCS(S, X, i, j-1);
    } else {
        prt_LCS(S, X, i-1, j);
    }
}

void calc_LCS(string& X, string& Y){
    vector<vector<int>> C;
    vector<vector<char>> S; // Position of LCS
    for (int i = 0; i < X.size(); i++){
        C.push_back(vector<int>(Y.size(), 0)); // Initialize C to a NxM matrix, each entry contains 0
        S.push_back(vector<char>(Y.size()));
    }

    for (int i = 1; i <X.size(); i++){
        for (int j = 1; j < Y.size(); j++){
            if (X[i] == Y[j]){
                C[i][j] = C[i-1][j-1] + 1;
                S[i][j] = 's'; // X[i] or Y[j] is one item of LCS
            } else if (C[i][j-1] > C[i-1][j]) {
                C[i][j] = C[i][j-1];
                S[i][j] = 'j'; // LCS(X[1..i], Y[1...j]) == LCS(X[1...i],Y[1...j-1])
            } else {
                C[i][j] = C[i-1][j];
                S[i][j] = 'i'; // LCS(X[1..i], Y[1...j]) == LCS(X[1...i-1],Y[1...j])
            }
        }
    }
    for (auto c :C){
        for (auto v : c){
            cout << v << " ";
        }
        cout << endl;
    }

    cout << endl;

    prt_LCS(S, X, X.size()-1, Y.size()-1);
}

int main()
{
    string X = " ACCGGGTTAC";
    string Y = " AGGACCA";
    cout << "X: " << X <<endl;
    cout << "Y: " << Y <<endl;
    calc_LCS(X, Y);
    return 0;
}
