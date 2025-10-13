#include <iostream>
#include <vector>
using namespace std;

bool dfsPathUtil(int start, int target, vector<vector<int>> adj, vector<int> &path, vector<bool> &visited)
{
    visited[start] = true;
    path.push_back(start);

    if (start == target)
    {
        return true;
    }
    for (int neighbour : adj[start])
    {
        if (!visited[neighbour])
        {

            if (dfsPathUtil(neighbour, target, adj, path, visited))
            {
                return true;
            }
        }
    }
    // if path is not found
    path.pop_back();
    return false;
}

void dfs(int start, int tar, vector<vector<int>> adj, int n)
{
    vector<bool> visited(n, false);
    vector<int> path;

    if (dfsPathUtil(start, tar, adj, path, visited))
    {
        cout << "Path is found" << endl;
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No path found" << endl;
    }
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
    dfs(0, tar, adj, size);
    return 0;
}