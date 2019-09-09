#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// problem： given a matrix, find the largest square of 1's
/*
 * For example, square like:
 * 11010
 * 01110
 * 11110
 * 01111
 *
 * will return 3
 */


// runtime - O(N*M)
int largestSquareOfOnes(vector<vector<int>> matrix){
    int height = matrix.size();
    int width = matrix.at(0).size();
    vector<vector<int>> cache(matrix);

    int result = 0;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (i == 0 || j ==0){
                continue;
            } else if (matrix[i][j] > 0){
                cache[i][j] = 1 + min(cache[i-1][j], min(cache[i][j-1], cache[i-1][j-1]));
            }

            if (cache[i][j] > result){
                result = cache[i][j];
            }
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> matrix = {{1,1,0,1,0},
                      {0,1,1,1,0},
                      {1,1,1,1,0},
                      {0,1,1,1,1}};
    cout << largestSquareOfOnes(matrix) << endl;
    return 0;
}
