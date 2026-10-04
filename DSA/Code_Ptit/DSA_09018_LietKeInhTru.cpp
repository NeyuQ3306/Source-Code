#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
vector<vector<int>> adj;
vector<int> dinhtru;
vector<bool> vis;

void dfs(int u){
    vis[u] = true;
    for(int x : adj[u]){
        if(!vis[x]) dfs(x);
    }
}

void solve() {
    cin >> n >> m;
    dinhtru.clear();
    adj.assign(n+1,{});
    vis.assign(n+1,false);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int k = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            ++k;
            dfs(i);
        }
    }

    for(int i=1; i<=n; i++){
        vis.assign(n+1,false);
        vis[i] = true;
        
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(!vis[j]){
                ++cnt;
                dfs(j);
            }
        }

        if(cnt > k) dinhtru.push_back(i);
    }

    if(dinhtru.size() > 0){
        for(int x : dinhtru) cout << x << " ";
        cout << endl;
    }
    else cout << "-1\n";
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