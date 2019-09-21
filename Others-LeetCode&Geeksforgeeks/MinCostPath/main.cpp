#include <iostream>

#define Row 3
#define Column 3

using namespace std;


int min (int x, int y, int z){
    if (x < y){
        return (x < z) ? x : z;
    } else {
        return (y < z) ? y : z;
    }
}

// Given a cost matrix cost[][] and a position (m,n) in cost[][]
// write a function that returns cost of minimum cost path to reach
// (m,n) from (0,0).

// simple solution: recursive - C implementation

int minCostPath(int cost[Row][Column], int m, int n){
    if (n < 0 || m < 0){
        return INT_MAX;
    } else if (m == 0 && n == 0){
        return cost[m][n];
    } else {
        return cost[m][n] + min(minCostPath(cost, m-1, n-1),
                                minCostPath(cost, m-1, n),
                                minCostPath(cost, m, n-1));
    }
}

// DP optimal - C implementation - O(mn)

int minCostDP(int cost[Row][Column], int m, int n){
    int i, j;

    // total cost
    int tc[Row][Column];

    tc[0][0] = cost[0][0];

    // initialize first column of total cost array
    for (i = 1; i <= m; i++){
        tc[i][0] = tc[i-1][0] + cost[i][0];
    }

    // initialize first row of total cost array
    for (j = 1; j <= n; j++){
        tc[0][j] = tc[0][j-1] + cost[0][j];
    }

    // the rest of tc
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            tc[i][j] = min(tc[i-1][j-1], tc[i-1][j], tc[i][j-1]) + cost[i][j];
        }
    }

    return tc[m][n];
}

int main()
{
    int cost[Row][Column] = {{1,2,3},
                             {4,8,2},
                             {1,5,3}};
    printf("%d \n", minCostPath(cost, 2, 2));
    printf("%d \n", minCostDP(cost, 2, 2));
    return 0;
}
