#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, char> PARENT;
unordered_map<char, int> RANK; // record the depth of trees
                               // make the complexity of Find better (Since it depends on the depth)

char Find(char vertex){
    if (PARENT[vertex] == vertex){
        return PARENT[vertex];
    } else {
        return Find(PARENT[vertex]);
    }
}

void Union(char root1, char root2){
    if (RANK[root1] > RANK[root2]){
        PARENT[root2] = root1;
    } else if (RANK[root2] > RANK[root1]){
        PARENT[root1] = root2;
    } else {
        PARENT[root1] = root2;
        RANK[root2]++;
    }
}

void MakeSet(char vertex){
    PARENT[vertex] = vertex;
    RANK[vertex] = 0;
}

/* Minimum Spanning Tree: The subset of edges that connects
 * all vertices in the graph. and has minimum total weight
 */

/*
 * Kruskal Algorithm:
 * Kruskal(V,E)
 *
 * A = empty
 * foreach v in V:
 *  Make-disjoint-set(v) // single disjointSet for each vertices
 *
 * Sort E by weight increasingly
 * foreach (v1, v2) in E:
 *  if Find(v1) # Find(v2):
 *      A = A + {(v1, v2)}:
 *      Union(v1, v2)
 *
 * return A
 */

struct Edge {
    char vertex1;
    char vertex2;
    int weight;
    Edge(char v1, char v2, int w) : vertex1(v1), vertex2(v2), weight(w) {}
};

struct Graph{
    vector<char> vertices;
    vector<Edge> edges;
};

void kruskal(Graph& g){
    vector<Edge> A;
    for (auto c: g.vertices){
        MakeSet(c);
    }

    //O(E * log(E))
    sort(g.edges.begin(), g.edges.end(), [](Edge x, Edge y) {return x.weight < y.weight;});

    for (Edge e : g.edges){
        char root1 = Find(e.vertex1);
        char root2 = Find(e.vertex2);
        if (root1 != root2){
            A.push_back(e);
            Union(root1, root2);
        }
    }

    for (Edge e : A){
        cout << e.vertex1 << "--" << e.vertex2 << " " << e.weight << endl;
    }
}

int main()
{
    char t[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    Graph g;
    g.vertices = vector<char>(t, t + sizeof(t)/sizeof(t[0]));

    g.edges.push_back(Edge('a', 'b', 4));
    g.edges.push_back(Edge('a', 'f', 2));
    g.edges.push_back(Edge('f', 'b', 5));
    g.edges.push_back(Edge('c', 'b', 6));
    g.edges.push_back(Edge('c', 'f', 1));
    g.edges.push_back(Edge('f', 'e', 4));
    g.edges.push_back(Edge('d', 'e', 2));
    g.edges.push_back(Edge('d', 'c', 3));

    kruskal(g);

    return 0;
}
