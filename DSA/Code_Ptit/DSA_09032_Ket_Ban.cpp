#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
vector<pair<int,int>> edge;
vector<int> par, sz;

void make_set(){
    for(int i=1; i<=n; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int u){
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

bool Union(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return false;
    if(sz[u] < sz[v]) swap(u,v);

    par[v] = u;
    sz[u] += sz[v];

    return true;
}

void solve() {
    cin >> n >> m;
    edge.clear();
    par.resize(n+1);
    sz.resize(n+1);
    make_set();

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        edge.push_back({x,y});
    }

    int ans = 1;
    for(auto x : edge){
        if(Union(x.first, x.second)){
            ans = max(ans, sz[find(x.first)]);
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