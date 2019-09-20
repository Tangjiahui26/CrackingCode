#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

/*
 * Step 1: Start with a brute force way
 *
 * Idea: Since we know that the if we want to search for kth multiple,
 * The biggest kth number could be 2^k + 3^k + 5^k, so a naive way is to
 * compute all the multiples and then sort them. Eventually we can pick
 * up the kth smallest value
 */

// brute force - O(k^3logk)
// calculate all the multiples and then sort to get the kth

/*
 * The runtime of this approach is O(k^3 * logk) since the runtime of allPossibleKFactors()
 * is O(k^3) and the sorting algorithm is O(k^3 * log(k^3))
 */

/*
 * We also need to handle the integer overflow, so here we used unsigned long long type.
 * Even so, this alogrithm is so slow, we cannot get the result of 30th multiple.
 */

vector<unsigned long long> allPossibleKFactors(int k){
    vector<unsigned long long> res;
    for (int a = 0; a <= k; a++){
        unsigned long long powA = pow(2, a);
        for (int b = 0; b <= k; b++){
            unsigned long long powB = pow(3, b);
            for (int c = 0; c <= k; c++){
                unsigned long long powC = pow(5, c);
                unsigned long long value = powA * powB * powC;

                if (value < 0 || powA == LONG_LONG_MAX || powB == LONG_LONG_MAX || powC == LONG_LONG_MAX){
                    value = LONG_LONG_MAX;
                }
                res.push_back(value);
            }
        }
    }
    return res;
}

int multipleOf235(int k){
    if (k <= 0) return 0;
    if (k == 1) return 1;
    vector<unsigned long long> values = allPossibleKFactors(k);
    sort(values.begin(), values.end());
    return values.at(k - 1);
}

/*
 * Step 2: Optimal Solution
 *
 * Idea: From the given examples we can find that the next value in the possible multiples list
 * will be one of these:
 *      2 * (some previous number in list)
 *      3 * (some previous number in list)
 *      5 * (some previous number in list)
 *
 * So we know that kth multiple can be expresses as (2, 3 or 5) * (some values in 1 to k-1th multiple).
 *
 * Here we can also do some calculation in advance. Each time we add a multple Mi to the list, we store the values
 * 2*Mi, 3*Mi and 5*Mi in some sort of temp list. In order to generate Mi+1, we search through this temp list and
 * find the smallest value.
 */

// improved approach using deque
int removeMin(deque<unsigned long long>& q){
    unsigned long long min = q.front();
    for (auto v : q){
        if (min > v){
            min = v;
        }
    }

    q.erase(std::remove(q.begin(), q.end(), min), q.end());
    return min;
}

void addProduct(deque<unsigned long long>& q, int v){
    q.push_back(v * 2);
    q.push_back(v * 3);
    q.push_back(v * 5);
}

unsigned long long multipleOf235UsingQueue(int k){
    if (k <= 0) return 0;
    if (k == 1) return 1;

    int val = 1;
    deque<unsigned long long> q;
    addProduct(q, 1);
    for (int i = 0; i < k - 1; i++){
        val = removeMin(q);
        addProduct(q, val);
    }
    return val;
}

/*
 * Step 3: More Optimal Solution
 *
 * Idea: Actally in previous algorithm, we did some silly work when trying to find the min value
 * because we checked all the multiples in the list. Hence, we can seperate one queue into three
 * different queue, and in order to get the min, we only need to look at the fronts of each queue.
 *
 * Also to avoid some duplicates when adding the multiples, we append x * 2, x * 3 and x * 5 in
 * three queues if we found x in queue2, append x * 3 and x * 5 in Queue3 and Queue5 if we found
 * x in Queue3, and only x * 5 in Queue5 if we found x in Queue5.
 */

// pseduocode here
/* 1. Initialize array and queue Q2, Q3, and Q5
 * 2. Insert 1 into array
 * 3. Insert 1*2, 1*3, 1*5 into Q2, Q3 and Q5 respectively
 * 4. Let x be the min element in Q2, Q3 and Q5. Append x into res
 * 5. If x was found in
 *    Q2 -> append x * 2, x * 3, x * 5 into Q2, Q3, and Q5. remove x from Q2
 *    Q3 -> append x * 3, x * 5 into Q3 and Q5. remove x from Q3
 *    Q5 -> append x * 5 into Q5. remove x from Q5
 * 6. Repeat 4-6 until we've found k element
 */

unsigned long long multipleOf235UsingOptimal(int k){
    if (k < 0){
        return 0;
    }

    if (k==1){
        return 1;
    }

    k = k - 1;

    unsigned long long val = 0;
    queue<unsigned long long> queue2;
    queue<unsigned long long> queue3;
    queue<unsigned long long> queue5;
    queue2.push(1);

    for (int i = 0; i <= k; i++){
        unsigned long long v2 = queue2.size() > 0 ? queue2.front() : LONG_LONG_MAX;
        unsigned long long v3 = queue3.size() > 0 ? queue3.front() : LONG_LONG_MAX;
        unsigned long long v5 = queue5.size() > 0 ? queue5.front() : LONG_LONG_MAX;
        val = min(v2, min(v3, v5));
        if (val == v2){
            queue2.pop();
            queue2.push(2 * val);
            queue3.push(3 * val);
        } else if (val == v3){
            queue3.pop();
            queue3.push(3 * val);
        } else if (val == v5){
            queue5.pop();
        }
        queue5.push(val * 5);
    }
    return val;
}

int main()
{
    cout << multipleOf235(18) << endl;
    cout << multipleOf235UsingQueue(1500) << endl;
    cout << multipleOf235UsingOptimal(1500) << endl;
    return 0;
}
