#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int largest_sum_cycle(int N, vector<int>& edge) {
    vector<vector<int>> graph(N);
    for (int i = 0; i < N; i++) {
        if (edge[i] != -1) {
            graph[i].push_back(edge[i]);
        }
    }

    int max_sum = -1;
    vector<bool> visited(N, false);
    vector<bool> rec_stack(N, false);

    function<void(int, int)> dfs = [&](int node, int current_sum) {
        visited[node] = true;
        rec_stack[node] = true;
        current_sum += node;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, current_sum);
            } else if (rec_stack[neighbor]) {
                max_sum = max(max_sum, current_sum);
            }
        }

        rec_stack[node] = false;
    };

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }

    return max_sum;
}

int main() {
    int N ;
    cin>> N;
    vector<int> edge(N) ;
    for(int i=0;i<N;i++){
        cin>>edge[i];
    }

    cout << largest_sum_cycle(N, edge) << endl;  // Output: 45
    return 0;
}
