# codingQuestions
record of all the solved dsa questions 

#for juspay test 
Here are implementations for the tasks you've requested:

### 1. Find the shortest path between two nodes in a weighted graph (using Dijkstra's algorithm):

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
typedef pair<int, int> pii;

vector<vector<pii>> g; // graph representation: adjacency list of pairs (destination, weight)

vector<int> dijkstra(int n, int start) {
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : g[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, e;
    cin >> n >> e;
    g.resize(n + 1);

    for (int i = 0; i < e; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }

    int start, end;
    cin >> start >> end;

    vector<int> shortest_dist = dijkstra(n, start);

    if (shortest_dist[end] == INF) {
        cout << "No path exists\n";
    } else {
        cout << "Shortest distance from " << start << " to " << end << " is: " << shortest_dist[end] << endl;
    }

    return 0;
}
```

### 2. Detect a cycle in a directed graph (using DFS with color coding):

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
enum Color { WHITE, GRAY, BLACK };
vector<int> g[N];
vector<Color> vis(N);

bool dfs(int u) {
    vis[u] = GRAY;

    for (int v : g[u]) {
        if (vis[v] == WHITE) {
            if (dfs(v)) return true;
        } else if (vis[v] == GRAY) {
            return true; // Found a back edge (cycle)
        }
    }

    vis[u] = BLACK;
    return false;
}

bool hasCycle(int n) {
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == WHITE) {
            if (dfs(i)) return true;
        }
    }
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    if (hasCycle(n)) {
        cout << "Graph contains cycle.\n";
    } else {
        cout << "Graph does not contain cycle.\n";
    }

    return 0;
}
```

### 3. Find the minimum spanning tree of a graph (using Kruskal's algorithm with Union-Find):

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<pair<int, pair<int, int>>> edges;
int parent[N], sz[N];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v) {
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
}

int kruskal(int n) {
    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto edge : edges) {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (find(u) != find(v)) {
            unite(u, v);
            cost += w;
        }
    }
    return cost;
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({w, {x, y}});
    }

    init(n);
    int minCost = kruskal(n);
    cout << "Minimum cost of MST: " << minCost << endl;

    return 0;
}
```

### 4. Implement a graph traversal algorithm (BFS):

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
vector<bool> vis(N);

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Process node u
        cout << u << " ";

        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x); // Uncomment for undirected graph
    }

    int start;
    cin >> start;

    bfs(start);
    cout << endl;

    return 0;
}
```

### 5. Find strongly connected components in a directed graph (using Kosaraju's algorithm):

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N], rg[N];
vector<bool> vis(N);
stack<int> st;

void dfs1(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    st.push(u);
}

void dfs2(int u, vector<int>& component) {
    vis[u] = true;
    component.push_back(u);
    for (int v : rg[u]) {
        if (!vis[v]) {
            dfs2(v, component);
        }
    }
}

vector<vector<int>> findSCCs(int n) {
    vector<vector<int>> scc;
    vis.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs1(i);
        }
    }

    vis.assign(n + 1, false);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!vis[u]) {
            vector<int> component;
            dfs2(u, component);
            scc.push_back(component);
        }
    }

    return scc;
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }

    vector<vector<int>> scc = findSCCs(n);

    cout << "Number of strongly connected components: " << scc.size() << endl;
    for (auto& component : scc) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
```

These implementations cover a variety of graph algorithms commonly used in competitive programming and real-world applications. Adjustments may be needed depending on specific input/output formats or additional requirements.
