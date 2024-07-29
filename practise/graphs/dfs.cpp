#include <bits/stdc++.h> 
using namespace std;
const int N = 1e5 +10;
vector<int> g[N];


vector<bool> visited(N);

void dfs(int vertex){
    /*
       visited is true 
    */

    visited[vertex] = true ;

    for(auto child : g[vertex]){
        /*
           take action before visiting the child 
           that is to check whether it visited or not 
        */
        
        if (visited[vertex] == true ) {
            continue ;
        }
        dfs(child);
    /*
       take action on the child after exiting the child 
    */

    }
    /*
       take action of vertex before exiting the vertex 
    */
    
    
    
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < m; i++){
        int v1, v2 ;
        cin>> v1>> v2 ;
        g[v1].push_back(v2);
        g[v2].push_back(v1);


    }
    
    
}

