#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// runtime: O(WH) Weight Hight

int computeSize(vector<vector<int>>& land, int r, int c){
    // base
    if (r < 0 || c < 0 || r >= land.size() || c >= land[0].size() || land[r][c] != 0){
        return 0;
    }

    int size = 1;
    land[r][c] = -1;
    // -1 0 1
    for (int dr = -1; dr <= 1; dr++){
        for(int dc = -1; dc <= 1; dc++) {
            size += computeSize(land, r + dr, c + dc);
        }
    }
    return size;
}

// modified BFS or DFS with a secondary visited matrix
vector<int> pondSize(vector<vector<int>>& land){
    vector<int> sizePond;
    for (size_t r = 0; r < land.size(); r++){
        for (size_t c = 0; c < land[0].size(); c++) {
            int size = computeSize(land, r, c);
            if (size > 0){
                sizePond.push_back(size);
            }
        }
    }
    return sizePond;
}

int main()
{
    vector<vector<int>> pondTest = {{0, 2, 1, 0},
                                   {0, 1, 0, 1},
                                   {1, 1, 0, 1},
                                   {0, 1, 0, 1}};
    vector<int> res = pondSize(pondTest);

    for (auto r : res) {
        cout << r << endl;
    }
    return 0;
}
