#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int v, int w) {
    adj[v].push_back(w); //with this function I'm pushing all the node and edge in the adj vector
}

bool DLS(vector<int> adj[], int v, int target, int depth) {
    if (depth == 0 && v == target)
        return true;
    if (depth > 0) {
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            if (DLS(adj, *i, target, depth - 1))
                return true;
    }
    return false;
}

bool IDS(vector<int> adj[], int src, int target, int max_depth) {
    for (int i = 0; i <= max_depth; i++)
        if (DLS(adj, src, target, i)) //it will call DLS 
            return true;
    return false;
}

int main() {
    const int V = 7; // Total 7 vertices in the graph
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 6);

    int target = 6; // it is my Target vertex to search
    int max_depth = 3; // Maximum depth to search i assinged 
    int src = 0; // this is source vertex , from here it will start

    if (IDS(adj, src, target, max_depth)) //calling the funtion 
        cout << "Target is reachable within max depth.\n";
    else
        cout << "Target is not reachable within max depth.\n";

    return 0;
}
