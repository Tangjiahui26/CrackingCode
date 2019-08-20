#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * Prim Algorithm
 *
 * A = empty
 * foreahc v in V:
 *  KEY[v] = max_int
 *  PARENT[v] = null
 * KEY[r] = 0 // r: root
 * Q = V
 *
 * while Q!=empty:
 *  u = min(Q) by KEY value
 *  Q = Q - u
 *  if PARENT(u) != null:
 *      A = A + (u, PARENT(u))
 *  foreach v in Adj(u):
 *      if v in Q and w(u, v) < KEY[v]:
 *          PARENT[v] = u
 *          KEY[v] = w
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

    vector<pair<char, Edge>> adjaceny(char u){
        vector<pair<char, Edge>> res;
        for (Edge e : edges){
            if (e.vertex1 == u){
                res.push_back(make_pair(e.vertex2, e));
            } else if (e.vertex2 == u){
                res.push_back(make_pair(e.vertex1, e));
            }
        }
        return res;
    }
};

void prim(Graph& g){
    unordered_map<char, char> A;
    unordered_map<char, char> PARENT;
    unordered_map<char, int> KEY;

    for (auto c: g.vertices){
        PARENT[c] = '\0';
        KEY[c] = INT_MAX;
    }

    KEY['a'] = 0; // ROOT
    vector<char> Q = g.vertices;

    while (!Q.empty()){
        char u = *std::min_element(Q.begin(), Q.end(), [&](char x, char y){return KEY[x] < KEY[y];});
        vector<char>::iterator itr = remove(Q.begin(), Q.end(), u); //O(v)
        Q.erase(itr, Q.end()); // erase() following remove() idiom
        if (PARENT[u] != '\0'){
            A[u] = PARENT[u];
        }

        vector<pair<char, Edge>> adj = g.adjaceny(u); // Q(E)
        for (pair<char, Edge> v : adj){
            if (find(Q.begin(), Q.end(), v.first) != Q.end()) { // Q(V)
                if (v.second.weight < KEY[v.first]) {
                    PARENT[v.first] = u;
                    KEY[v.first] = v.second.weight;
                }
            }
        }
    }

    for (auto e: A){
        cout << e.first << "--" << e.second << endl;
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

    prim(g);

    return 0;
}
