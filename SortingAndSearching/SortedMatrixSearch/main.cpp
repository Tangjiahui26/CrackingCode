#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sortedMatrixSearch(const vector<vector<int>> matrix, const int target){
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    int row = 0;
    int col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0){
        if (matrix[row][col] == target){
            return true;
        } else if (matrix[row][col] > target){
            col--;
        } else {
            row++;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> test = {{15, 20, 40, 85},
                                {20, 35, 80, 95},
                                {30, 55, 95, 105},
                                {40, 80, 100, 200}};
    int target = 80;
    string result = sortedMatrixSearch(test, target) ? "true" : "false";
    cout << "Given target = " << target << ", return " << result;
    return 0;
}
