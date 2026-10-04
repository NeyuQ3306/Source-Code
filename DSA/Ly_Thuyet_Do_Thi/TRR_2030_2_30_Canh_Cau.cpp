#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;


/* Ý tưởng:

*/

const long long mod = 1e9 + 7;
int n,m,u;
vector<set<int>> adj;
vector<set<int>> adjs;
vector<bool> vis;
vector<int> ideg;
vector<int> odeg;
vector<int> path;
vector<vector<int>> ke;
vector<vector<int>> lt;
vector<vector<int>> ts;
set<pair<int,int>> edge;
vector<pair<int,pair<int,int>>> canh;
vector<vector<int>> CC;
vector<int> tmp;

void dfs1(int u){
    vis[u] = true;

    for(int x : adj[u]){
        if(!vis[x])
            dfs1(x);
    }
}

void dfs2(int u, int s, int t){
    vis[u] = true;

    for(int v : adj[u]){
        if((u == s && v == t) || (u == t && v == s)) continue;
        else if(!vis[v]) dfs2(v,s,t);
    }
}

void solve() {
    cin >> n;
    ke.assign(n+1,vector<int>(n+1));
    adj.assign(n+1,{});
    edge.clear();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> ke[i][j];

            if(ke[i][j] && i < j){
                adj[i].insert(j);
                adj[j].insert(i);
                edge.insert({i,j});
            }
        }
    }

    int k = 0;
    vis.assign(n+1,false);

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs1(i);
            ++k;
        }
    }

    vector<pair<int,int>> ans;
    for(auto x : edge){
        int s = x.fi, t = x.se;
        vis.assign(n+1,false);

        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                ++cnt;
                dfs2(i,s,t);
            }
        }

        if(cnt > k){
            ans.push_back({s,t});
        }
    }

    cout << ans.size() << endl;
    for(auto x : ans)
        cout << x.fi << " " << x.se << endl;

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);
    #else
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}