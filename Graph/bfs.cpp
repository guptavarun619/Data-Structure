#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

template<typename T>

class Graph {
    map<T, list<T> > l;

public:
    void addNode(T x, T y) {
        l[x].emplace_back(y);
        l[y].emplace_back(x);
    }

    void bfs(T src) {
        map<T, bool> visited;
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            cout << q.front() << ", ";
            // l[q.front()]
            for(auto nbr : l[q.front()]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
            q.pop();
        }
    }
};

int32_t main() {
    Graph<int> g;
    g.addNode(0,1);
    g.addNode(1,2);
    g.addNode(2,3);
    g.addNode(3,4);
    g.addNode(3,0);
    g.addNode(4,5);

    g.bfs(0);

    return 0;
}