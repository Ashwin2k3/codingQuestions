#include <bits/stdc++.h> 
using namespace std;
const int N = 1e5 + 10;
int dp[N];
int main(){
    int n;
    cin>>n;
    int dp[N];
    dp[0]=1;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        dp[i] = 2 * dp[i-2];

    }
    cout << dp[n] << endl;
}

