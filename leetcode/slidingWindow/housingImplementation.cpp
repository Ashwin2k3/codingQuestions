#include <bits/stdc++.h> 
using namespace std;
void housing(vector<int> a, int n , int k){
    int j=0;
    int i=0;
    int sum = 0;
    while (j<n) {   
        sum += a[j];
        j++;
        while(i<j and sum > k){
            sum -= a[i];
            i++;
        }
        if(sum ==k){
            for(int x = i;x<j;x++){
                cout << a[x]<< " ";
            }
            cout<< endl;

        }
    }
    

}
int main(){
    vector<int> a{1,3,2,1,4,1,3,2,1,1};
    int n = a.size();
    int k = 8;

    housing(a,n,k);

}

