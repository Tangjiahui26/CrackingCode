#include <iostream>
#include <algorithm>
#include <array>
#include <stack>


using namespace std;

int getMiddle(int from, int to){
    return 3 - (from + to);
}

void printTowers(const array<std::stack<int>, 3> & stacks){
    for (const auto & s: stacks){
        for (size_t i = 0; i < s.size(); i++){
            cout << "|";
        }
        cout << endl;
    }
    cout << endl;
}

void towersOfHanoi(array<std::stack<int>, 3> & stacks, int count, int from, int to){
    if(count == 1){
        int t = stacks[from].top();
        stacks[from].pop();
        stacks[to].push(t);
        return;
    }

    int mid = getMiddle(from, to);
    towersOfHanoi(stacks, count - 1, from, mid);
    towersOfHanoi(stacks, 1, from, to);
    towersOfHanoi(stacks, count - 1, mid, to);
}

int main()
{
    array<std::stack<int>, 3> test;
    test[0].push(4);
    test[0].push(3);
    test[0].push(2);
    test[0].push(1);
    towersOfHanoi(test, 4, 0, 2);
    printTowers(test);
    return 0;
}
