#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, int target, vector<vector<int>> graph, int n)
{
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == target)
        {
            break;
        }
        for (int neighbour : graph[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
                parent[neighbour] = node;
            }
        }
    }
    if (!visited[target])
    {
        cout << "No path exists" << endl;
        return;
    }

    vector<int> path;
    for (int v = target; v != -1; v = parent[v])
    {
        path.push_back(v);
    }
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> adj(5);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {1, 2};

    int size = 5;
    int tar = 4;
    bfs(0, tar, adj, size);

    return 0;
}