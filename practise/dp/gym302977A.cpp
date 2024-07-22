#include <bits/stdc++.h> 
using namespace std;
int find(int n){
    if (n==0) {
        return 0;
    }
    if (n==1) {
        return 0;
    }
    return find(n) = 2*find(n-2);
}
int main(){
    int n;
    cin>>n;
   // int cnt=0;
   // while(n%2==0){
   //     n = n-2;
   //     cnt ++;

   // }
   // cout<< cnt * 2;
   // 
   cout<<find(n);
   return 0;
}

