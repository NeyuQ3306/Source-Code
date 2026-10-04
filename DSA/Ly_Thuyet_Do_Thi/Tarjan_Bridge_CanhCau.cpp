#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int n, m;

int timer = 0;
int disc[MAXN], low[MAXN];
bool visited[MAXN];

vector<pair<int,int>> bridges;

void DFS(int u, int parent) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;

    for (int v : adj[u]) {
        if (v == parent) continue;

        if (!visited[v]) {
            DFS(v, u);

            low[u] = min(low[u], low[v]);

            // Điều kiện cạnh cầu
            if (low[v] > disc[u]) {
                bridges.push_back({u, v});
            }
        } 
        else {
            // back edge
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) DFS(i, -1);
    }

    for (auto [u, v] : bridges) {
        cout << u << " " << v << "\n";
    }
}