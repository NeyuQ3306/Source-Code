#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
vector<vector<int>> adj(1001);
vector<bool> vis(1001);

void dfs(int v){
    vis[v] = true;
    for(int x : adj[v]){
        if(!vis[x]) dfs(x);
    }
}

void solve() {
    cin >> n >> m;
    adj.assign(n+1,{});

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for(int i=1; i<=n; i++){
        vis.assign(n+1,false);
        dfs(i);

        for(int j=1; j<=n; j++){
            if(!vis[j]){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
              
    while(t--){
       solve(); 
    }
    return 0;
}