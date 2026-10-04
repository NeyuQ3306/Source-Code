#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int n, m;

int timer = 0;
int disc[MAXN], low[MAXN];
bool in_stack[MAXN]; 
stack<int> st; // stack chứa các đỉnh chưa biết thuộc SCC nào
// Các đỉnh cùng thuộc 1 SCC sẽ nằm liên tiếp nhau trong stack, coi u với low(u) = disc(u) là root của SCC đó

int scc_count = 0;

void DFS(int u) {
    disc[u] = low[u] = ++timer;
    st.push(u);
    in_stack[u] = true;

    for (int v : adj[u]) {
        if (!disc[v]) {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_stack[v]) {
            // chỉ update nếu v còn trong stack
            low[u] = min(low[u], disc[v]);
        }
    }

    // Chạy tới đây là đã duyệt xong toàn bộ các node con của u <=> disc, low của v là con của u đều đã được xác định đúng
    // nếu u là root của SCC
    if (low[u] == disc[u]) {
        scc_count++;
        cout << "SCC " << scc_count << ": ";

        while (true) {
            int v = st.top(); st.pop();
            in_stack[v] = false;

            cout << v << " ";
            if (v == u) break;
        }
        cout << "\n";
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); // đồ thị có hướng
    }

    for (int i = 1; i <= n; i++) {
        if (!disc[i]) DFS(i);
    }
}