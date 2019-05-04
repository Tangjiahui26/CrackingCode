#include <iostream>
#include <vector>


using namespace std;

bool rotateMatrix(vector<vector<int>> &matrix) {
    if (matrix.size() == 0 || matrix.size() != matrix[0].size()) {
          return false;
    } else {
        int n = matrix.size();
        for (int layer = 0; layer < n / 2; layer++) {
            int first = layer;
            int last = n - 1 -layer;
            for (int i = first; i < last; i++) {
                int offset = i - first;
                int top = matrix[first][i];
                matrix[first][i] = matrix[last-offset][first];
                matrix[last-offset][first] = matrix[last][last-offset];
                matrix[last][last-offset] = matrix[i][last];
                matrix[i][last] = top;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    if (rotateMatrix(matrix)){
        for (vector<int> const& innerVec : matrix){
            for (int element : innerVec) {
                cout << element << ",";
            }
            cout << endl;
        }
    } else {
        cout << "Not able to rotate!" << endl;
    }
    return 0;
}
