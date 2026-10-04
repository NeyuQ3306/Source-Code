#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Thuật toán Kosaraju - Bài toán thành phần liên thông mạnh của G có hướng
B1: Gọi dfs trên G ban đầu và lưu thứ tự đỉnh theo finishing time vào stack (toposort)
B2: Đảo chiều các cung của G ban đầu được TG (Transpose graph)
B3: Pop từng đỉnh stack ra và gọi dfs(top) trên TG

- Độ phức tạp: O(2*(V+E))
- SCC in ra là SCC trên TG 
*/

int n,m;
vector<vector<int>> adj,r_adj;
vector<bool> vis;
stack<int> topo;

// topo sort
void dfs1(int u){
    vis[u] = true;
    for(int x : adj[u]){
        if(!vis[x]) dfs1(x);
    }

    topo.push(u);
}

// find SCC - Strongly Connected Componment(Thành phần liên thông mạnh)
void dfs2(int u){
    vis[u] = true;
    cout << u << " ";
    for(int x : r_adj[u]){
        if(!vis[x]) dfs2(x);
    }
}

void solve() {
    cin >> n >> m;
    adj.assign(n+100,{}), r_adj.assign(n+100,{});
    vis.assign(n+100,false);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs1(i);
    }

    int cnt = 0;
    vis.assign(n+1,false);
    while(!topo.empty()){
        int v = topo.top();
        topo.pop();

        if(!vis[v]){
            ++cnt;
            dfs2(v);
            cout << endl;
        }
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
              
    while(t--){
       solve(); 
    }
    return 0;
}