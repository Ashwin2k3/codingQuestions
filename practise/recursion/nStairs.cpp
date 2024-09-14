#include <bits/stdc++.h> 
using namespace std;
int Nstairs(int n){
    if(n==0){
        return 1;
    }
    if (n<0) {
        return 0;
    }
    return  Nstairs(n-1)+Nstairs(n-2)+Nstairs(n-3);
}
int main(){
    int n;
    cin>>n;
    cout << Nstairs(n);
}

