#include <bits/stdc++.h> 
using namespace std;
int last(int a[],int n, int key){
    if(n==0){
        return -1;

    }

    int subIndex = last(a+1, n-1, key);
    if (subIndex == -1) {
        if (a[0]==key) {
            return 0;
        }
        else{
            return -1;
        }
    }
    else{
        return subIndex + 1 ;
    }

}
int main(){
    int a[] = {1,3,4,5,6,6,7,8,0};
    int n= sizeof(a)/sizeof(int);
    int key = 6;
    cout << last(a,n,key);
    
}
