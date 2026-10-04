#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
vector<bool> visited(1005,false);
vector<vector<int>> adj(1000+1);

void dfs(int v){
    visited[v] = true;
    for(int x : adj[v]){
        if(!visited[x]) dfs(x);
    }
}


void solve() {
    cin >> n >> m;
    visited.clear(), visited.resize(n+1,0);
    adj.clear(), adj.resize(n+1);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            ++ans;
            dfs(i);
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