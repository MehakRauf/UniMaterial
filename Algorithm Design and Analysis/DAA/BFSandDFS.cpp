#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> adj, int size)
{
    queue<int> q;
    vector<bool> visited(size, false);

    visited[start] = true;
    q.push(start);
    cout << "BFS traversal" << endl;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

void dfsUtil(int node, vector<vector<int>> adj, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfsUtil(neighbour, adj, visited);
        }
    }
}
void dfs(int start, vector<vector<int>> adj, int size)
{
    vector<bool> visited(size, false);
    cout << "DFS traversal: " << endl;
    dfsUtil(start, adj, visited);
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
    dfs(0, adj, size);

    return 0;
}