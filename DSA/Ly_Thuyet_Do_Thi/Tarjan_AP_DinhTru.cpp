#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int n, m;

int timer = 0;
int disc[MAXN], low[MAXN];
bool visited[MAXN];
bool isArticulation[MAXN];

void DFS(int u, int parent) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;

    int children = 0; // số con trong DFS tree

    for (int v : adj[u]) {
        if (v == parent) continue;

        if (!visited[v]) {
            children++;
            DFS(v, u);

            low[u] = min(low[u], low[v]);

            // Điều kiện đỉnh trụ (không phải root)
            if (parent != -1 && low[v] >= disc[u]) {
                isArticulation[u] = true;
            }
        } 
        else {
            // back edge
            low[u] = min(low[u], disc[v]);
        }
    }

    // Trường hợp root
    if (parent == -1 && children > 1) {
        isArticulation[u] = true;
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

    for (int i = 1; i <= n; i++) {
        if (isArticulation[i]) cout << i << " ";
    }
}