#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<set<int>> powerSet(const set<int>& origin_set){
    set<set<int>> sets;
    sets.insert(origin_set);

    for (int i : origin_set){
        set<int> origin_set_copy(origin_set);
        origin_set_copy.erase(i);
        for (const set<int>& subset: powerSet(origin_set_copy)) {
            sets.insert(subset);
        }
    }
    return sets;
}

int main()
{
    set<int> test = {0, 1, 2, 3};
    set<set<int>> results = powerSet(test);
    for (const set<int> & s : results){
        cout << "{ ";
        for (int i : s) {
            cout << i << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}
