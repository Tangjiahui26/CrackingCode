#include <iostream>
#include <list>
#include <algorithm>
#include <stack>

using namespace std;

// DFS simple implementation

class Graph {
    int V; // number of vertices
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);
public:
    Graph(int V); // constructor
    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    // runtime O(V+E)
    void DFS(int v);
    void topologicalSort();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true;
    // print vertex first
    cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i]){
            DFSUtil(*i, visited);
        }
    }
}

void Graph::DFS(int v){
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }

    DFSUtil(v, visited);
}

// topological sorting
/*
 * In topological sorting, we use a temporary stack.
 * We don’t print the vertex immediately, we first
 * recursively call topological sorting for all its
 * adjacent vertices, then push it to a stack.
 * Finally, print contents of stack. Note that a
 * vertex is pushed to stack only when all of its
 * adjacent vertices (and their adjacent vertices
 *  and so on) are already in stack.
 */

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack){
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if(!visited[*i]){
            topologicalSortUtil(*i, visited, Stack);
        }
    }
    Stack.push(v);
}

void Graph::topologicalSort(){
    stack<int> Stack;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }

    for (int i = 0; i < V; i++){
        if (visited[i] == false){
            topologicalSortUtil(i, visited, Stack);
        }
    }

    while(Stack.empty() == false){
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
    cout << endl;

    Graph g2(6);
    g2.addEdge(5, 2);
    g2.addEdge(5, 0);
    g2.addEdge(4, 0);
    g2.addEdge(4, 1);
    g2.addEdge(2, 3);
    g2.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g2.topologicalSort();
    return 0;
}
