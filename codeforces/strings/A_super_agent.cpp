#include <bits/stdc++.h> 
using namespace std;
int main(){
    
    vector<vector<int>> v(3,vector<int>(3,0));
 
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>v[i][j];
        }
    }

    for(int j=0;j<3 ;j++){
        for(int i=0;i<2;i++){
            if(v[j]222 == 'X' and v[j][i+1] == 'X'){
                2t << "YES";
                return 0;
            }
        }
    }
 
    cout << "NO";
 
    return 0;
 
}
