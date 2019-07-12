#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// without using DP
int makeChange(int amount, const vector<int> & denoms, int index){
    if (index == denoms.size() - 1) {
        return 1;
    }

    int denoms_amount = denoms[index];
    int ways = 0;
    for (int i = 0; i <= amount; i += denoms_amount){
        int remaining = amount - i;
        ways += makeChange(remaining, denoms, index + 1);
    }
    return ways;
}

int main()
{
    const vector<int> coins = {25, 10, 5, 1};
    for (int i = 1; i <= 25; i++){
        cout << "Ways to represent " << i << " cents: " << makeChangeDP(i, coins) << endl;
    }
    return 0;
}
