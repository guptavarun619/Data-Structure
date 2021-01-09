#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; // no of vertex
    // Array of List
    list<int> *l;
    public:
    // constructor
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAdjList() {
        // Iterate over adjectency list
        for(int i=0; i<V; i++) {
            cout << "Vertex " << i << " -> ";
            for(int x: l[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif    

    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);

    g.printAdjList();
    
    return 0;
}