#include <bits/stdc++.h>
using namespace std;


int dfs(int curr_node, vector<vector<int>>& r_graph, vector<int>& num_ways, vector<int>& visited) {
    if (visited[curr_node] == 1) {
        return 0;
    }
    if (num_ways[curr_node] != -1) {
        return num_ways[curr_node];
    }
    int M = 10 ** 9 + 7;
    int acc = 0;
    visited[curr_node] = 1;
    for (int prev_node: r_graph[curr_node]) {
        acc = (acc + dfs(prev_node, r_graph, num_ways)) % M;
    }
    num_ways[curr_node] = acc;
    visited[curr_node] = 0;
    return acc;
}


int counts_paths(int n, vector<vector<int>>& graph, vector<vector<int>>& r_graph) {
    vector<int> num_ways(n + 1, -1);
    vector<int> visited(n + 1, 0);
    num_ways[1] = 1;

    visited[n] = 1
    int answer = 0;
    for (int prev_node: r_graph[n]) {
        if (sum(visited) == n) {}
        answer += dfs(node, r_graph, num_ways, visited);
    return answer;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, e;
    cin >> n >> e;

    vector<vector<int>> graph(n + 1);
    vector<vector<int>> r_graph(n + 1);

    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        r_graph[v].push_back(u);
    }

    int answer = count_paths(n, graph, r_graph);
    cout << answer << endl;
}