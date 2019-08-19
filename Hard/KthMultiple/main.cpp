#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

// brute force - O(k^3logk)
// calculate all the multiples and then sort to get the kth

vector<int> allPossibleKFactors(int k){
    vector<int> res;
    for (int a = 0; a <= k; a++){
        int powA = pow(3, a);
        for (int b = 0; b <= k; b++){
            int powB = pow(5, b);
            for (int c = 0; c <= k; c++){
                int powC = pow(7, c);
                int value = powA * powB * powC;

                if (value < 0 || powA == INT_MAX || powB == INT_MAX || powC == INT_MAX){
                    value = INT_MAX;
                }
                res.push_back(value);
            }
        }
    }
    return res;
}

int getKthMagicNumber(int k){
    if (k <= 0) return 0;
    if (k == 1) return 1;
    vector<int> values = allPossibleKFactors(k);
    sort(values.begin(), values.end());
    return values.at(k - 1);
}

// optimal
// pseduocode here
/* 1. Initialize array and queue Q3, Q5, and Q7
 * 2. Insert 1 into array
 * 3. Insert 1*3, 1*5, 1*7 into Q3, Q5 and Q7 respectively
 * 4. Let x be the min element in Q3, Q5 and Q7. Append x into res
 * 5. If x was found in
 *    Q3 -> append x * 3, x * 5, x * 7 into Q3, Q5, and Q7. remove x from Q3
 *    Q5 -> append x * 5, x * 7 into Q5 and Q7. remove x from Q5
 *    Q7 -> append x * 7 into Q7. remove x from Q7
 * 6. Repeat 4-6 until we've found k element
 */

int getKthMagicNumberOptimal(int k){
    if (k < 0){
        return 0;
    }

    if (k==1){
        return 1;
    }

    k = k - 1;

    int val = 0;
    queue<int> queue3;
    queue<int> queue5;
    queue<int> queue7;
    queue3.push(1);

    for (int i = 0; i <= k; i++){
        int v3 = queue3.size() > 0 ? queue3.front() : INT_MAX;
        int v5 = queue5.size() > 0 ? queue5.front() : INT_MAX;
        int v7 = queue7.size() > 0 ? queue7.front() : INT_MAX;
        val = min(v3, min(v5, v7));
        if (val == v3){
            queue3.pop();
            queue3.push(v3 * 3);
            queue3.push(v3 * 5);
        } else if (val == v5){
            queue5.pop();
            queue5.push(v5 * 5);
        } else if (val == v7){
            queue7.pop();
        }
        queue7.push(val * 7);
    }
    return val;
}

int main()
{
    cout << getKthMagicNumber(2) << endl;
    cout << getKthMagicNumberOptimal(2) << endl;
    return 0;
}
