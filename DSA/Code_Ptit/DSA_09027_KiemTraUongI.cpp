#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/
int n,m;
vector<vector<int>> adj(1001);
int comp[1001];

void dfs(int v, int id){
    comp[v] = id;

    for(int x : adj[v]){
        if(comp[x] == 0){
            dfs(x,id);
        }
    }
}

void solve() {
    cin >> n >> m;
    // .resize() + .clear() = .assign()
    // adj.clear(), adj.resize(n+1);
    adj.assign(n+1,{});
    memset(comp,0,sizeof(comp));

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int id = 0;
    for(int i=1; i<=n; i++){
        if(comp[i] == 0){
            ++id;
            dfs(i,id);
        }
    }

    int q;
    cin >> q;
    while(q--){
        int s,t;
        cin >> s >> t;

        if(comp[s] == comp[t]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
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