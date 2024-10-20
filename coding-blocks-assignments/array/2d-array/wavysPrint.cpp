
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define INF LLONG_MAX

// Data structures
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define unordered_map_um unordered_map
#define unordered_set_um unordered_set
#define pb push_back
#define mp make_pair

// Functions for debugging
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define debugArray(arr, n) for (int i = 0; i < n; ++i) cerr << arr[i] << " "; cerr << endl

// Functions for common operations
template<typename T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a * b / gcd(a, b); }
template<typename T> T power(T x, T y, T p) {
    T res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Sorting comparison function for descending order
template<typename T> bool sortDesc(const T &a, const T &b) { return a > b; }

// Custom hash functions for unordered_map
struct customHash {
    size_t operator()(const pair<int, int> &p) const {
        return hash<long long>()(((long long)p.first) ^ (((long long)p.second) << 32));
    }
};

void solve() {
    // Your code for solving each test case

     int M, N;

    // Read the dimensions of the array
    cin >> M >> N;

    vector<vector<int>> arr(M, vector<int>(N));

    // Read the elements of the array
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    // Wave print the array column-wise
    for (int j = 0; j < N; ++j) {
        if (j % 2 == 0) { // Even index column: top to bottom
            for (int i = 0; i < M; ++i) {
                cout << arr[i][j];
                if (i != M - 1 || j != N - 1) cout << ", ";
            }
        } else { // Odd index column: bottom to top
            for (int i = M - 1; i >= 0; --i) {
                cout << arr[i][j];
                if (i != 0 || j != N - 1) cout << ", ";
            }
        }
    }

    // Print "END" at the end
    cout << ", END" << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
	
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

