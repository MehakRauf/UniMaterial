#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w; 
};

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionSets(int u, int v, vector<int>& parent) {
    parent[findParent(u, parent)] = findParent(v, parent);
}

int main() {
    int V = 4; 
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });

    vector<int> parent(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    int totalCost = 0;
    cout << "Edges in MST:\n";

    
    for (auto edge : edges) {
        int uParent = findParent(edge.u, parent);
        int vParent = findParent(edge.v, parent);

        if (uParent != vParent) {  // no cycle
            cout << edge.u << " - " << edge.v << " : " << edge.w << endl;
            totalCost += edge.w;
            unionSets(edge.u, edge.v, parent);
        }
    }

    cout << "Total Minimum Cost = " << totalCost << endl;
    return 0;
}
