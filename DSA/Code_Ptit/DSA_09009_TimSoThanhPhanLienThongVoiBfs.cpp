#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
vector<vector<int>> adj(1001);
vector<bool> vis(1001);

void bfs(int v){
    queue<int> q;
    q.push(v);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int x : adj[u]){
            if(!vis[x]){
                q.push(x);
                vis[x] = true;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    vis.clear(), vis.resize(n+1,false);
    adj.clear(), adj.resize(n+1);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ll ans = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            ++ans;
            bfs(i);
        }
    }

    cout << ans << endl;
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