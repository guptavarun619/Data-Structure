#include<iostream>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph {
    map<T, list<T> > l;

public:
    void addNode(int x, int y) {
        l[x].emplace_back(y);
        l[y].emplace_back(x);
    }

    void dfs_helper(T src, map<T,bool> &visited) {
        cout << src << ", ";
        visited[src] = true;
        for(auto nbr: l[src]) {
            if(!visited[nbr]) {
                dfs_helper(nbr, visited);
            }
        }
        return;
    }

    void dfs(T src) {
        map<T,bool> visited;
        // Mark all the nodes as not visited
        for(auto node: l) 
            visited[node.first] = false;

        dfs_helper(src, visited);

    }
};

int32_t main() {
    Graph<int> g;
    g.addNode(0,1);
    g.addNode(0,3);
    g.addNode(1,2);
    g.addNode(2,3);
    g.addNode(3,4);
    g.addNode(4,5);

    g.dfs(4);

    return 0;
}