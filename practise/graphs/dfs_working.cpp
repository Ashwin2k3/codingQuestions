/*
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
*/
#include <bits/stdc++.h> 
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
vector<bool> visited(N, false); // Initialize visited array with false

void dfs(int vertex) {
    cout << vertex << endl;
    visited[vertex] = true;

    for (auto child : g[vertex]) {
        cout << "parent " << vertex << ", child : " << child << endl;
        if (!visited[child]) {
            dfs(child);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    int start_vertex = 1; // Choose a starting vertex for DFS
    dfs(start_vertex);

    return 0;
}

