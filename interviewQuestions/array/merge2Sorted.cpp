#include <bits/stdc++.h> 
using namespace std;
vector<int> mergeSorted(vector<int>v1,vector<int>v2){
    int s1 = v1.size();
    int s2 = v2.size();
    vector<int> v3(s1+s2);
    int i=0,j=0,k=0;
    while (i<s1 and j<s2) {   
        if (v1[i] < v2[j]) {
            
            v3[k++] = v1[i++];
        }
        else{
            v3[k++] = v2[j++];
        }

    }
    while (i<s1) {   
        v3[k++]= v1[i++];
    }
    while (j<s2) {   
        v3[k++] = v2[j++];
    }
    return v3;
}
int main(){
    vector<int> v1{1,2,3};

    vector<int> v2{3,4,5,6,7};


    vector<int> v;
    v = mergeSorted(v1,v2);

    for(auto it : v){
        cout << it << " ";
    }
    
    return 0;
    

}

