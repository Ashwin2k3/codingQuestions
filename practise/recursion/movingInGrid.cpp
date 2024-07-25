#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> findPath(vector<vector<int>> v ){
    
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,0);
    findPath(v);
    for(auto it : v){
        for(int i=0;i<it.size();i++){
            cout << it[i]<< " ";

        }
        cout << endl;
    }

}

