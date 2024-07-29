#include <bits/stdc++.h> 
using namespace std;
const int N=1e3 + 10;
int graph1[N][N];

vector<int> g[N];//here we made n verticise 
 
// incase of wt in the adjecency list 
vector<pair <int,int>> g1[N];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int v1, v2;
        cin >> v1 >> v2 ;
         graph1[v1][v2] =1;
         graph1[v2][v1] =1;
         g[v1].push_back(v2);
         g[v2].push_back(v1);
         
         /*
            space in adjecency list is O(n+m)
            here we can also put n = 10^5 as well  
         */
         
         // for the weighted graph we will write 
         g1[v1].push_back({v2,wt});
         g1[v2].push_back({v1,wt});

          

    }
}

