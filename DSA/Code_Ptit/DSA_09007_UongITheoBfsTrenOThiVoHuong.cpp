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

void bfs(int v){
    queue<int> q;
    q.push(v);
    vis[v] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int x : adj[u]){
            if(!vis[x]){
                vis[x] = true;
                parent[x] = u;
                q.push(x);
            }
        }
    }
}

void path(){
    bfs(s);
    if(!vis[t]) cout << "-1\n";
    else{
        vector<int> res;
        while(s != t){
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
    vis.assign(n+1, false);
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