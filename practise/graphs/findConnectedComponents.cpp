#include <bits/stdc++.h> 
/*
   vertex ,Edges 
    8 5
    1 2
    2 3
    2 4
    3 5
    6 7
*/

using namespace std;
const int N =1e5 + 10;
bool vis[N];
vector<int> g[N];

void dfs(int vertex) {

    vis[vertex] = true;

    for (auto child : g[vertex]) {

        if (!vis[child]) {
            dfs(child);
        }
    }
}
int main(){
    int n,e ;
    cin >> n >> e ;
    for(int i=0 ; i < e; ++i){
        int x , y;
        cin>>x>> y;

        g[x].push_back(y);
        g[y].push_back(x);

        //count of connected components 
    }
    int cnt = 0;
    // now for all nodes we will run dfs 
    for(int i=0; i<=n; i++){
        if (vis[i]) {
            continue;
        }
        dfs(i);
        cnt ++;
    }
    cout << cnt << endl;
}

