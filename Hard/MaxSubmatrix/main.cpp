#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// brute force - O(n^6)

class SubMatrix{
private:
    int row1;
    int row2;
    int col1;
    int col2;
    int sum;

public:
    SubMatrix(){
        row1 = 0;
        col1 = 0;
        row2 = 0;
        col2 = 0;
        sum = 0;
    }
    SubMatrix(int r1, int c1, int r2, int c2, int sm){
        row1 = r1;
        col1 = c1;
        row2 = r2;
        col2 = c2;
        sum = sm;
    }
    int getSum(){
        return sum;
    }
    int getRow1(){
        return row1;
    }
    int getRow2(){
        return row2;
    }
    int getCol1(){
        return col1;
    }
    int getCol2(){
        return col2;
    }
};

int sum(vector<vector<int>> matrix, int row1, int col1, int row2, int col2){
    int sum = 0;
    for (int r = row1; r <= row2; r++){
        for (int c = col1; c <= col2; c++){
            sum += matrix[r][c];
        }
    }
    return sum;
}

SubMatrix getMaxMatrix(vector<vector<int>> matrix){
    int rowCount = matrix.size();
    int columnCount = matrix[0].size();
    SubMatrix best = SubMatrix();
    for (int row1 = 0; row1 < rowCount; row1++){
        for (int row2 = row1; row2 < rowCount; row2++){
            for (int col1 = 0; col1 < columnCount; col1++){
                for (int col2 = col1; col2 < columnCount; col2++){
                    int s = sum(matrix, row1, col1, row2, col2);
                    if (best.getSum() == 0 || best.getSum() < s){
                        best = SubMatrix(row1, col1, row2, col2, s);
                    }
                }
            }
        }
    }
    return best;
}

// optimal solution - DP to precompute the sum - O(N^4)
// for example, we have the following rectangle:
/*
 *            x1   x2
 *   ----------------------
 *   |    A    |  C  |    |
 * y1|---------------------
 *   |    B    |  D  |    |
 * y2|--------------------|
 *   |                    |
 *   |--------------------|
 *
 * So ValD = area(point(0, 0) -> point(x2, y2)
 *
 * area(D) = valD - area(A union C) - area(A union B) + area(A)
 *
 * Val(x, y) = val(x-1, y) + Val(y-1, x) - Val(x-1, y-1) + M[x][y]
 */

// better solution: Using the alogrithm in the question of find the maximum subarray
// It can be realized as a O(R^C) alogrithm


int main()
{
    vector<vector<int>> m = {{1, 2, -3, 4},
                             {3, -1, 4, 6},
                             {3, 4, 5, -15}};
    SubMatrix res = getMaxMatrix(m);
    cout << res.getSum() << endl;
    cout << res.getCol1() << "-" << res.getCol2() << endl;
    cout << res.getRow1() << "-" << res.getRow2() << endl;
    return 0;
}
