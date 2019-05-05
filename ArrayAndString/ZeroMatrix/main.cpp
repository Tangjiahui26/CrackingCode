#include <iostream>
#include <vector>

using namespace std;

void nullifyRow(vector<vector<int>> &matrix, int row){
    for (size_t j = 0; j < matrix[0].size(); j++) {
        matrix[row][j] = 0;
    }
}

void nullifyColumn(vector<vector<int>> &matrix, int column){
    for (size_t i = 0; i < matrix.size(); i++) {
        matrix[i][column] = 0;
    }
}

vector<vector<int>> setZero(vector<vector<int>> &matrix){
    vector<vector<int>> result = matrix;
    bool row[result.size()];
    bool column[result[0].size()];

    for (size_t i = 0; i < result.size(); i++){
        for (size_t j = 0; j < result[0].size(); j ++) {
            if (result[i][j] == 0) {
                row[i] = true;
                column[j] = true;
            }
        }
    }

    for (size_t i = 0; i < result.size(); i++) {
        if (row[i])
            nullifyRow(result, i);
    }

    for (size_t j = 0; j < result[0].size(); j++) {
        if (column[j])
            nullifyColumn(result, j);
    }
    return result;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 0, 6},
                                  {7, 8, 9},
                                  {11, 12, 13}};

    cout << "Original Matrix: " << endl;
    for (vector<int> const& innerVec : matrix){
        for (int element : innerVec) {
            cout << element << ",";
        }
        cout << endl;
    }

    vector<vector<int>> resultMatrix = setZero(matrix);
    cout << "Result Matrix: " << endl;
    for (vector<int> const& innerVec : resultMatrix){
        for (int element : innerVec) {
            cout << element << ",";
        }
        cout << endl;
    }
    return 0;
}
