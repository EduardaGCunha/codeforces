#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

void dfs(int v, int x, vector<vector<int>> &graph, vector<int> &visited, vector<int> &ignore) {
    visited[v] = 1;
    for (auto u : graph[v]) {
        if (u == x) {
            ignore[v] = 1;
            continue;
        }
        if (!visited[u]) {
            dfs(u, x, graph, visited, ignore);
        }
    }
}

void dfs2(int v, int x, int y, vector<vector<int>> &graph, vector<int> &visited) {
    visited[v] = 1;
    for (auto u : graph[v]) {
        if (u == x || u == y) continue;
        if (!visited[u]) {
            dfs2(u, x, y, graph, visited);
        }
    }
}

signed main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b;
            a--; b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        if (n == 2) {
            cout << 0 << endl;
            continue;
        }

        int mx_degree = 0, x = 0;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() > mx_degree) {
                mx_degree = graph[i].size();
                x = i;
            }
        }

        vector<int> visited(n, 0);
        vector<int> ignore(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == x) continue;
            if (!visited[i]) {
                dfs(i, x, graph, visited, ignore);
            }
        }

        int mx = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (i == x) continue;
            int cnt = ignore[i];
            int current = graph[i].size() - cnt;
            if (current > mx) {
                mx = current;
                y = i;
            }
        }

        vector<int> visited2(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i == x || i == y) continue;
            if (!visited2[i]) {
                cnt++;
                dfs2(i, x, y, graph, visited2);
            }
        }

        cout << cnt << endl;
    }
}