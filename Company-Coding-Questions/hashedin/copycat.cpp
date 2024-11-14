#include <bits/stdc++.h> 
using namespace std;
int main(){
    
    vector<string> s ;
    string s1 ;

    cin.getline(s1);

    string rahuls_words ;
    cin.getline(rahuls_words);

    stringstream  s(s1);

    string temp ;
    while (getline(s, temp, ' ')) {   
        s.push_back(temp);

    }
    
    vector<string> v2 ;

    stringstream ss(rahuls_words);
    while(getline(ss, temp, ' ')){
        v2.push_back(temp);
    }

    for(int i=0;i<v2.size();i++){
        if (s[i] != v2[i]) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

