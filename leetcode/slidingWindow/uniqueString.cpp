#include <bits/stdc++.h> 
using namespace std;
string unique_substring(string str){
    int i=0;
    int j=0;
    int windowSize =0;
    int maxWindowSize = 0;
    int start_window = -1;
    
    unordered_map<char ,int> m;
    while(j<str.length()){
        char ch = str[j];

        // if the inside hashmap is greater than the size of the current window 
        if (m.count(ch)!=0 and m[ch] >=i) {

        }
        m[ch] = j;
        windowSize++;
    }
}
int main(){
    string input;
    cin>>input;
    cout << unique_substring(input);

    return 0;
}

