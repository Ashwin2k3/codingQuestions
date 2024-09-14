#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int n, const vector<int>& e, vector<bool>& visited, vector<bool>& stack, vector<int>& sum) {
    if (visited[n]) return stack[n] ? n : -1;
    visited[n] = stack[n] = true;
    int next = e[n], cycle_start = -1;
    if (next != -1) cycle_start = dfs(next, e, visited, stack, sum);
    stack[n] = false;
    if (cycle_start != -1) {
        sum[n] = (n == cycle_start ? 0 : sum[next]) + n;
        if (n == cycle_start) cycle_start = -1;
    }
    return cycle_start;
}

int largestSumCycle(int N, const vector<int>& e) {
    vector<bool> visited(N, false), stack(N, false);
    vector<int> sum(N, 0);
    int max_sum = -1;
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) dfs(i, e, visited, stack, sum);
        max_sum = max(max_sum, sum[i]);
    }
    return max_sum == 0 ? -1 : max_sum;
}

int main() {
    int N;
    cin >> N;
    vector<int> e(N);
    for (int i = 0; i < N; ++i) cin >> e[i];
    cout << largestSumCycle(N, e) << endl;
    return 0;
}
