#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    unordered_map<string, int> count;
    pair<string, int> result("", 0);
    for (int i = 0; i < n - 1; ++i)
        if (++count[s.substr(i, 2)] > result.second)
            result = {s.substr(i, 2), count[s.substr(i, 2)]};
    cout << result.first << endl;
    return 0;
}

