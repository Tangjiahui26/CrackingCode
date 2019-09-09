#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// similar to the question about PondSize, to calculate the number of island,
// we can also use DFS with visit marking.

int isSafe(vector<vector<int>>& matrix, int r, int c, vector<vector<bool>>& visited){
    return (r >= 0) && (r < matrix.size()) && (c >= 0) && (c < matrix[0].size()) && (matrix[r][c] && !visited[r][c]);
}

void DFS(vector<vector<int>>& matrix, int r, int c, vector<vector<bool>>& visited){
    // 8 neighbours of a given cell
    static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // mark as visited
    visited[r][c] = true;

    for (int k = 0; k < 8; ++k){
        // if its valid
        if (isSafe(matrix, r + rowNbr[k], c + colNbr[k], visited)){
            DFS(matrix, r + rowNbr[k], c + colNbr[k], visited);
        }
    }
}

int countIslands(vector<vector<int>>& matrix){
    int count = 0;
    vector<vector<bool>> visited(matrix[0].size(), vector<bool>(matrix.size(), false));
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[0].size(); ++j){
            if (matrix[i][j] && !visited[i][j]){
                DFS(matrix, i, j, visited);
                ++count;
            }
        }
    }
    return count;
}

// follow-ups: Find the number of distinct islands in a 2D matrix

// basic idea, we can take first coordinates of any island as a base point
// and then compute the coordinates of other points from the base point, then store
// it into a set to elminate duplicates.

void DFS2(vector<vector<int>>& matrix, int x0, int y0,
          int r, int c, vector<pair<int, int>>& v){
    // 8 neighbours of a given cell
    static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size()
            || matrix[r][c] <= 0){
        return;
    }

    // marking
    matrix[r][c] *= -1;

    // computing coordinates with x0, y0 as base
    v.push_back({r - x0, c - y0});

    for (int k = 0; k < 8; ++k){
        DFS2(matrix, x0, y0, r + rowNbr[k], c + colNbr[k], v);
    }
}

int countDistinctIslands(vector<vector<int>>& matrix){
    int r = matrix.size();
    int c = matrix[0].size();
    if (r == 0 || c == 0){
        return 0;
    }

    set<vector<pair<int, int>>> coordinates;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if (matrix[i][j] != 1){
                continue;
            }

            vector<pair<int, int>> v;
            DFS2(matrix, i, j, i, j, v);
            coordinates.insert(v);
        }
    }

    return coordinates.size();
}


int main()
{
    vector<vector<int>> test = {{1,1,0,0,0},
                                {0,1,0,0,1},
                                {1,0,0,1,1},
                                {0,0,0,0,0},
                                {1,0,1,0,1}};

    cout << "Number of islands is: " << countIslands(test) << endl;
    cout << "Number of distinct islands is: " << countDistinctIslands(test) << endl;
    return 0;
}
