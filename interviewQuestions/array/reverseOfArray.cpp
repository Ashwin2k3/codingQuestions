#include <bits/stdc++.h> 
using namespace std;

int main() {
    vector<int> a{1,2,3,4,5,6};
    int i = 0;
    int j = a.size() - 1;

    while(i < j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }

    for(auto it : a) {
        cout << it << " ";
    }
    return 0;
}

