#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#define ll long long

using namespace std;

vector<vector<ll>> adj; // Adjacency list
vector<ll> visited; // 0 = unvisited, 1 = visiting, 2 = visited
vector<ll> order; // Stores the topological order
vector<ll> mainCourses; // List of main courses
ll n, k; // Number of courses and main courses

bool dfs(ll course) {
    if (visited[course] == 1) return false; // Cycle detected
    if (visited[course] == 2) return true;  // Already processed

    visited[course] = 1; // Mark as visiting
    for (ll prereq : adj[course]) {
        if (!dfs(prereq)) return false;
    }
    visited[course] = 2; // Mark as visited
    order.push_back(course); // Add to order list as it finishes
    return true;
}

vector<ll> findOrder() {
    // Initiate DFS from each course to ensure all prerequisites are visited
    for (ll i = 1; i <= n; ++i) {
        if (visited[i] == 0) {
            if (!dfs(i)) {
                return {-1}; // Cycle detected
            }
        }
    }

    // Ensure all main courses are included in the topological order
    unordered_set<ll> mainSet(mainCourses.begin(), mainCourses.end());
    for (ll course : order) {
        mainSet.erase(course);
    }

    if (!mainSet.empty()) return {-1}; // Not all main courses can be reached

    // Since we need the courses in the order they are taken, reverse the order
    reverse(order.begin(), order.end());
    return order;
}

int main() {
    cin >> n >> k;
    mainCourses.resize(k);
    adj.resize(n + 1);
    visited.resize(n + 1, 0);

    for (ll i = 0; i < k; ++i) {
        cin >> mainCourses[i];
    }

    for (ll i = 1; i <= n; ++i) {
        ll t;
        cin >> t;
        for (ll j = 0; j < t; ++j) {
            ll prereq;
            cin >> prereq;
            adj[i].push_back(prereq);
        }
    }

    vector<ll> result = findOrder();
    if (result.size() == 1 && result[0] == -1) {
        cout << -1 << endl;
    } else {
        cout << result.size() << endl;
        for (ll course : result) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}

