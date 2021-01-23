#include <bits/stdc++.h>
using namespace std;

class Graph {
    // Adj List
    unordered_map<string, list<pair<string, int>>> l;

    public:
        void addEdge(string x, string y, bool bidir, int wt) {
            l[x].push_back(make_pair(y,wt));
            if(bidir)
                l[y].push_back(make_pair(x,wt));
        }

        void printAdjList() {
            // Iterate over all the keys in the map
            for(auto p :l) {
                string city = p.first;
                cout << city << "-> ";
                list<pair<string, int>> nbrs = p.second;
                for(auto nbr: nbrs) {
                    string dest = nbr.first;
                    int dist = nbr.second;
                    cout << dest << " " << dist << ",";
                }
                cout << endl;
            }
        }
};

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif    
    
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("A","D",false, 50);
    g.addEdge("B","D",true,30);
    g.addEdge("D","C",true,40);
    g.addEdge("C","A",true,10);

    g.printAdjList();

    return 0;
}