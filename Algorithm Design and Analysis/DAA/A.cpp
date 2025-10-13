#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// Move up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Manhattan Distance (used as heuristic)
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

struct Node {
    int x, y;
    int g, f;
    bool operator>(const Node &other) const {
        return f > other.f;
    }
};

void aStar(vector<vector<int>> &grid, int sx, int sy, int gx, int gy) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> cost(n, vector<int>(m, 1e9));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    pq.push({sx, sy, 0, heuristic(sx, sy, gx, gy)});
    cost[sx][sy] = 0;

    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();
        int x = curr.x, y = curr.y;

        if (x == gx && y == gy) {
            cout << "Reached Goal! Minimum cost = " << curr.g << endl;
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0) {
                int newG = curr.g + 1;
                int newF = newG + heuristic(nx, ny, gx, gy);

                if (newG < cost[nx][ny]) {
                    cost[nx][ny] = newG;
                    pq.push({nx, ny, newG, newF});
                }
            }
        }
    }
    cout << "No Path Found!" << endl;
}

int main() {
    // 0 = road, 1 = obstacle
    vector<vector<int>> city = {
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    // Start (0,0), Goal (4,4)
    aStar(city, 0, 0, 4, 4);

    return 0;
}
