#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m,s,t;
vector<vector<int>> adj(1001);
vector<bool> vis(1001);
int parent[1001];

void dfs(int v){
    vis[v] = true;
    for(int x : adj[v]){
        if(!vis[x]){
            parent[x] = v;
            dfs(x);
        }
    }
}

void path(){
    dfs(s);
    if(!vis[t]) cout << "-1\n";
    else{
        vector<int> res;
        while(t != s){
            res.push_back(t);
            t = parent[t];
        }

        res.push_back(s);
        reverse(res.begin(), res.end());
        for(int x : res) cout << x << " ";
        cout << endl;
    }
}

void solve() {
    cin >> n >> m >> s >> t;
    adj.assign(n+1,{});
    vis.assign(n+1,false);
    memset(parent,0,sizeof(parent));

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    path();
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