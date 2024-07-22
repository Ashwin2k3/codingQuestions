#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj; // Adjacency list
vector<bool> visited;    // Visited array
vector<bool> in_path;    // In path during DFS
int cycle_count = 0;     // Count of cycles

void dfs(int v, int parent) {
    visited[v] = true;
    in_path[v] = true;
    
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, v);
        } else if (in_path[u] && u != parent) {
            cycle_count++;
        }
    }
    
    in_path[v] = false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n + 1);
    visited.assign(n + 1, false);
    in_path.assign(n + 1, false);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Find cycles in connected components
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }
    
    cout << cycle_count << endl;
    
    return 0;
}

