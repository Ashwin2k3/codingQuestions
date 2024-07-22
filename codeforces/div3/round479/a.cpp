#include <bits/stdc++.h> 
using namespace std;
int main(){
    
    int N, K;
    cin>>N>>K;
    while(K--){
        if(N%10==0){
            N /= 10;

        }
        else{
            N -= 1;
        }
    }
    cout<<N;
}

