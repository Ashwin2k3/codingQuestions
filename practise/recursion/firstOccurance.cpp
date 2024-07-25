
#include <bits/stdc++.h> 
using namespace std;
int FirstOccurance(int a[],int i, int n,int key){
    if (a[i]==key and i <n {
       return i;
    }
    FirstOccurance(a ,i+1, n , key);
}
int main(){
    int a[] = {1 ,2,3,4,5,6,7};
    int n = sizeof(a)/sizeof(int);
    int key ;
    cin>> key;
    int i=0;

    cout << FirstOccurance(a ,i, n,key);
}

