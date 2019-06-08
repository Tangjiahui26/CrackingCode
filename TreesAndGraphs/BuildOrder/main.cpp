#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>

using namespace std;

// using topological sort

struct node {
    node(char data) : data(data) {}
    char data;
    vector<node*> dependers;
    int numberOfDependencies = 0;
};

typedef vector<node*> nodes;
typedef pair<node*, node*> node_pair;
typedef vector<node_pair> node_pairs;

vector<node*> buildOrder(nodes &_nodes, node_pairs& dep_pairs){
    vector<node*> ordered_nodes;

    set<node*> without_deps;
    for(node* _node : _nodes){
        without_deps.insert(_node);
    }

    set<node*> with_deps;
    for(node_pair& _node_pair : dep_pairs){
        _node_pair.first->dependers.push_back(_node_pair.second);
        _node_pair.second->numberOfDependencies++;
        with_deps.insert(_node_pair.second);
        without_deps.erase(_node_pair.second);
    }

    while(!without_deps.empty()){
        node* dependency = *without_deps.begin();
        ordered_nodes.push_back(dependency);
        without_deps.erase(dependency);
        for (node* depender : dependency->dependers){
            depender->numberOfDependencies--;
            if(depender->numberOfDependencies == 0){
                with_deps.erase(depender);
                without_deps.insert(depender);
            }
        }
    }

    if(!with_deps.empty()){
        throw "Cycle!";
    }

    return ordered_nodes;
}

int main()
{
    // initialization
    node a('a');
    node b('b');
    node c('c');
    node d('d');
    node e('e');
    node f('f');

    nodes _nodes = {&a, &b, &c, &d, &e, &f};

    node_pairs deps = {
        node_pair(&a, &d),
        node_pair(&f, &b),
        node_pair(&b, &d),
        node_pair(&f, &a),
        node_pair(&d, &c),
    };

    for (node* _node : buildOrder(_nodes, deps)) {
        cout << _node->data << " ";
    }
    cout << endl;
    return 0;
}
