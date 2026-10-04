#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n, timer;
vector<vector<int>> adj;
vector<int> low,id;
vector<bool> AP, vis;
vector<pii> bridge;

void tarjan(int u, int par){
    vis[u] = true;
    low[u] = id[u] = ++timer;
    int child = 0;
    
    for(int x : adj[u]){
        if(x == par) continue;

        if(!vis[x]){
            ++child;
            tarjan(x,u);
            low[u] = min(low[u], low[x]);

            if(par != -1 && low[x] >= id[u]){
                AP[u] = true;
            }
        }

        else{
            low[u] = min(low[u], id[x]);
        }
    }

    if(par == -1 && child >= 2){
        AP[u] = true;
    }
}

void solve() {
    cin >> n;
    timer = 0;
    adj.assign(n+1,{});
    low.assign(n+1,0);
    id.assign(n+1,0);;
    AP.assign(n+1,false);
    bridge.clear();
    vis.assign(n+1,false);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin >> x;

            if(x){
                adj[i].push_back(j);
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]) tarjan(i,-1);
    }

    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(AP[i]) ++cnt;
    }

    
    cout << cnt << endl;
    for(int i=1; i<=n; i++){
        if(AP[i]) cout << i << " ";
    }
    cout << endl;
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