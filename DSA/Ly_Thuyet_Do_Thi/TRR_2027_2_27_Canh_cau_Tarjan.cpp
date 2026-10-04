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

int n,timer;
vector<int> id,low;
vector<vector<int>> adj;
vector<pii> bridge;
vector<bool> vis;

void tarjan(int i, int par){
    vis[i] = true;
    id[i] = low[i] = ++timer;

    for(int x : adj[i]){
        if(x == par) continue;

        if(!vis[x]){
            tarjan(x,i);
            low[i] = min(low[i], low[x]);

            if(low[x] > id[i]){
                bridge.push_back({min(x,i), max(i,x)});
            }s
        }

        // backedge
        else{
            low[i] = min(low[i], id[x]);s
        }
    }
}

void solve() {
    cin >> n;
    timer = 0;
    id.assign(n+1,0);
    low.assign(n+1,0);
    adj.assign(n+1,{});
    bridge.clear();
    vis.assign(n+1,false);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin >> x;

            if(x) adj[i].push_back(j);
        }
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]) tarjan(i,-1);
    }

    cout << bridge.size() << endl;
    sort(bridge.begin(), bridge.end());
    
    for(auto x : bridge){
        cout << x.fi << " " << x.se << endl;
    }
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while(t--){
       solve(); 
    }
    return 0;
}