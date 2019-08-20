#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// build Dusjoint_set class using hash table

class Disjoint_set {
    unordered_map<char, char> PARENT;
    unordered_map<char, int> RANK; // record the depth of trees
                                   // make the complexity of Find better (Since it depends on the depth)
public:
    Disjoint_set(){
        char universe[] = {'a', 'b', 'c', 'd', 'e'};
        for (char x : universe){
            PARENT[x] = x;
            RANK[x] = 0;
        }
        PARENT['d'] = 'b';
        RANK['b'] = 1;
    }

    char Find(char item){
        if (PARENT[item] == item){
            return item;
        } else {
            return Find(PARENT[item]);
        }
    }

    void Union(char set_1, char set_2){
        if (RANK[set_1] > RANK[set_2]){
            PARENT[set_2] = set_1;
        } else if (RANK[set_2] > RANK[set_1]){
            PARENT[set_1] = set_2;
        } else {
            PARENT[set_1] = set_2;
            RANK[set_2]++;
        }
    }
};

int main()
{
    Disjoint_set ds;
    cout << ds.Find('c') << endl;; // return 'c'
    ds.Union('c', 'a'); // 'a' and 'c' are in the same set
    cout << ds.Find('c') << endl; // return 'a'
    ds.Union('a', 'b'); // 'a', 'c' 'b', 'd' are in the same set
    return 0;
}
