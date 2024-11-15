#include <bits/stdc++.h> 
using namespace std;
void formatProducts(int a , int b){
    int res =1 ;
    for(int i=a; i<=b; i++){
        res = res * i;
    }
    int temp = res;
    int power = 0;
    while ((res % 10) == 0) {   
        power = power + 1 ;
        res = res / 10;
    }
    cout << res << " * 10^" << power ;
    
}
int main(){
    int a , b;
    cin>> a >> b;
    formatProducts(a,b);


}


