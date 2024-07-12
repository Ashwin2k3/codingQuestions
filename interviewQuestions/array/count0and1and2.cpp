#include <bits/stdc++.h> 
using namespace std;
int main(){
    
    vector<int> v{1,2,2,0,0,0,1,};

    int cnt1 =v.count(1);
    int cnt2 = v.count(2);
    int cnt3 = v.count(0);
    for(int i=0;i<cnt3;i++){
        v[i]=0;
    }
    for(int i=cnt3;i<cnt3+cnt2)
}

