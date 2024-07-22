#include <bits/stdc++.h> 
using namespace std;
const int N = 1e5+10;
int dp[N];
int fact(int n){
    if (n==0) {
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = n * fact(n-1);
}
int main(){
    int n;
    cin>>n;
    cout << fact(n)<<endl;
    return 0;
}
