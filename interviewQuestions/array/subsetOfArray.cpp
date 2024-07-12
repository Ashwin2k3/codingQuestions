/*
   
   logic it to insert the values of v in an unordered_set 
   - then check all the values of v2 one by one whether it exists in set
   - if it doesnt exist then return no
        else return true 
*/

#include <bits/stdc++.h> 
using namespace std;
int main(){
    vector<int> v{11,2,13,21,3,7};
    vector<int> v2{11,13,3};
    unordered_set<int> s;
    for(auto it : v){
        s.insert(it);
    }

    bool issubset = true;
    for(int i=0;i<v2.size();i++){
        if(s.find(v2[i])==0){
           issubset = false; 
        }
    }
    if(issubset){
        cout<< "yes";

    }
    else{
        cout << " no ";
    }
}

