/*
   

class Solution {
public:
    void dfs(int node,vector<int> adj[], vector<int> &vis){
        vis[node] =1 ;
        for(auto it : adj[node]){
            if (!vis[it] and vis[node] !=-1) {
                dfs(it,adj,vis);
            }
        }

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj(n,-1);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            if (u != v) {
                adj[u] = v ;
                adj[v] = u;
            }
        }
        vector<int> vis(n,0);
        int cnt =0;
        for(int i=1;i<=n;i++){
            if (!vis[i]) {
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt ;

    
}
};

*/
class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;

        for(auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if(u != v) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};

