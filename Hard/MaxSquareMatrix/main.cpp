#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// brute force - O(N^4)

struct Subsquare{
    int row;
    int col;
    int squareSize;
    Subsquare(int r, int c, int s){
        row = r;
        col = c;
        squareSize = s;
    }
};

bool isSquare(vector<vector<int>> matrix, int row, int col, int size){
    // check top and bottom border
    for (int j = 0; j < size; j++){
        if (matrix[row][col+j] == 1){
            return false;
        }

        if (matrix[row+size-1][col+j] == 1){
            return false;
        }
    }

    // check left and right border
    for (int i = 0; i < size; i++){
        if (matrix[row+i][col] == 1){
            return false;
        }

        if (matrix[row+i][col+size-1] == 1){
            return false;
        }
    }
    return true;
}

Subsquare findSquareWithSize(vector<vector<int>> matrix, int squareSize){
    int count = matrix.size() - squareSize + 1;

    for (int row = 0; row < count; row++){
        for (int col = 0; col < count; col++){
            if (isSquare(matrix, row, col, squareSize)){
                return Subsquare(row, col, squareSize);
            }
        }
    }
    return Subsquare(0, 0, 0);
}

Subsquare findSquare(vector<vector<int>> matrix){
    for (int i = matrix.size(); i >= 1; i--){
        Subsquare square = findSquareWithSize(matrix, i);
        if (square.squareSize != 0){
            return square;
        }
    }
    return Subsquare(0, 0, 0);
}

int main()
{
    vector<vector<int>> m = {{0, 0, 0, 1},
                             {0, 0, 0, 0},
                             {0, 0, 0, 1},
                             {1, 1, 1, 1}};
    Subsquare res = findSquare(m);
    cout << res.col << "-" << res.row << "-" << res.squareSize << endl;
    return 0;
}
