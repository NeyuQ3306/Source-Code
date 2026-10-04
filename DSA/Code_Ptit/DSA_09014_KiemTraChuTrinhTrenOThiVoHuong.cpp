#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/
int n,m;
vector<vector<int>> adj(1001);
vector<bool> vis(1001);


bool dfs(int v, int par){
    vis[v] = true;
    for(int x : adj[v]){
        if(!vis[x]){
            if(dfs(x,v)) return true;
        }

        else if(x != par) return true;
    }

    return false;
}
void solve() {
    cin >> n >> m;
    adj.assign(n+1,{});
    vis.assign(n+1,false);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(i,0)){
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
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