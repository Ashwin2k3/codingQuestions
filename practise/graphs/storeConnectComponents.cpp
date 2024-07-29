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
vector<vector<int> > cc ;
vector<int> current_cc;


void dfs(int vertex) {

    vis[vertex] = true;

    current_cc.push_back(vertex);
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
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
        cnt ++;
    }
    cout << cc.size() << endl;
    for(auto it : cc){
        for(auto a : it){
            cout << a << " ";
        }
        cout << endl;
    }
}


