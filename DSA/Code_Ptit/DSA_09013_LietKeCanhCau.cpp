#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
vector<vector<int>> adj(1001);
vector<pair<int,int>> edge(1001);
vector<bool> vis(1001);

void dfs1(int v, int s, int t){
    vis[v] = true;
    for(int x : adj[v]){
        if((x == s && v == t) || (x == t && v == s)) continue; // bo qua canh (s,t)
        else if(!vis[x]) dfs1(x,s,t);
    }
}

void dfs2(int v){
    vis[v] = true;
    for(int x : adj[v]){
        if(!vis[x]) dfs2(x);
    }
}

void cnt_canhcau(){
    int k = 0;
    vis.assign(n+1, false);

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            ++k;
            dfs2(i);
        }
    }

    for(auto it : edge){
        int s = it.first, t = it.second; // canh can bo qua
        vis.assign(n+1, false);
        int cnt = 0;
        
        for(int j=1; j<=n; j++){
            if(!vis[j]){
                ++cnt;
                dfs1(j,s,t);
            }
        }

        if(cnt > k) cout << s << " " << t << " ";
    }

    cout << endl;
}

void solve() {
    cin >> n >> m;
    adj.assign(n+1,{});
    edge.assign(n+1,{});

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
        edge.push_back({x,y});
    }

    cnt_canhcau();
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