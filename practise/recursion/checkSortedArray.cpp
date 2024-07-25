#include <bits/stdc++.h> 
using namespace std;
bool isSorted(int a[] , int n){
    //base case :
    if(n==1 or n==0){
        return true ;
    }
    //recursive case: 
    if(a[0]<a[1] and isSorted(a + 1, n-1)){
        return true ;
    }
    return false;
}
bool isSorted2(int a[], int n,int i){
    if(i==n-1){
        return true ;
    }
    if (a[i]<a[i+1] and isSorted2(a,n,i+1)) {
        return true ;
    }
    return false ;
}
int main(){
    int a[] = {1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(int);

    cout << (isSorted(a,n) == 1)?"is sorted":"not sorted";
    cout << endl;
    cout << (isSorted2(a,n,0) == 1)?"is sorted":"not sorted";
    
}

