#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// DFS Recursive Function
void dfs(unordered_map<string, vector<string>>& web, string start, string target, set<string>& visited, bool& found) {
    cout << start << " -> ";
    visited.insert(start);
    if (start == target) {
        cout << "\nPage found using DFS!" << endl;
        found = true;
        return;
    }

    for (auto& link : web[start]) {
        if (!visited.count(link) && !found)
            dfs(web, link, target, visited, found);
    }
}

// BFS Function
void bfs(unordered_map<string, vector<string>>& web, string start, string target) {
    set<string> visited;
    queue<string> q;
    q.push(start);

    while (!q.empty()) {
        string page = q.front();
        q.pop();
        cout << page << " -> ";
        if (page == target) {
            cout << "\nPage found using BFS!" << endl;
            return;
        }
        visited.insert(page);
        for (auto& link : web[page]) {
            if (!visited.count(link))
                q.push(link);
        }
    }
    cout << "\n Page not found." << endl;
}

int main() {
    unordered_map<string, vector<string>> web = {
        {"Google", {"YouTube", "Gmail", "Maps"}},
        {"YouTube", {"Music", "News"}},
        {"Gmail", {"Contacts", "Drive"}},
        {"Maps", {"Location", "Directions"}},
        {"Drive", {"Photos"}},
        {"Music", {}}, {"News", {}}, {"Contacts", {}},
        {"Photos", {}}, {"Location", {}}, {"Directions", {}}
    };

    string start = "Google";
    string target = "Drive";

    cout << "\nDFS Web Search for '" << target << "':\n";
    set<string> visited;
    bool found = false;
    dfs(web, start, target, visited, found);

    cout << "\nBFS Web Search for '" << target << "':\n";
    bfs(web, start, target);

    return 0;
}