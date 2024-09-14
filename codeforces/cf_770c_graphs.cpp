#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> adj;
vector<int> visited;
vector<int> order ;
int n, k;
vector<int> mainCourses;


bool dfs(int course){
    if (visited[course] == 1 ) {
        return false ;
    }
    if (visited[course] ==2 ) {
        return true ;
    }
    visited[course] =1 ;
    for(int prereq : adj[course ]){
        if (!dfs(prereq)) {
            return false ;
        }
    }
    visited[course] =2 ;
    order.push_back(course);
    return true;
}

vector<int> findOrder(){
    for(int i=1 ;i <= n; i++){
        if (visited[i] == 0) {
            if (!dfs(i)) {
                return {-1};
            }
        }
    }
    unordered_set<int> mainSet(mainCourses.begin(), mainCourses.end());
    for(int course: order){
        mainSet.erase(course);
    }
    if(!mainSet.empty()){
        return { -1  };
    }
   reverse(order.begin(), order.end());
   return order  ;
}

int main(){
    cin>> n>> k;
    mainCourses.resize(k);
    adj.resize(n+1);
    visited.resize(n+1,0);

    for(int i=0;i<k;i++){
        cin>> mainCourses[i];
    }

    for(int i=1; i<=n;i++){
        int t ;
        cin>> t;
        for(int j=0;j<t;j++){
            int prereq;
            cin>> prereq;
            adj[i].push_back(prereq);
        }
    }
    vector<int> result = findOrder();
    if (result.size() == 1 && result[0] == -1) {
        cout << -1 << endl;
    } else {
        cout << result.size() << endl;
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
