#include <bits/stdc++.h> 
using namespace std;
int findPath(int n,int m){
    if (n==1 or m==1) {
        return 1 ;
    }
    return findPath(n,m-1) + findPath(n-1,m);
}
int main(){
    int n,m;
    cin>>n>>m;
    cout << " the total ways of reaching to the bottom right is : "<< findPath(n,m);
}

