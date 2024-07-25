#include <bits/stdc++.h> 
using namespace std;
int ways(int n, int m){
    if (n==0 ) {
        return 1;
    }
    if (m==0) {
        return 0;
    }
    return ways(n-1,m) + ways(n,m-1);
}
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    
    cout << "no of ways of partitioning is : "<<ways(n,m);
}

