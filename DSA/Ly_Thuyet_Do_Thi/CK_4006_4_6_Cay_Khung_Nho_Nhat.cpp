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
vector<int> par,sz;

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
    if(sz[u] < sz[v])
        swap(u,v);

    par[v] = u;
    sz[u] += sz[v];

    return true;
}

void solve() {
    cin >> n;
    par.assign(n+1,0);
    sz.assign(n+1,0);
    canh.clear();

    make_set();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin >> x;

            if(x != 0 && x != 10000 && i < j){
                canh.push_back({x,{i,j}});
            }
        }
    }

    sort(canh.begin(), canh.end());
    vector<pair<int,pair<int,int>>> mst;
    int wt = 0;

    for(auto x : canh){
        if(mst.size() == n-1)
            break;

        int u = x.se.fi, v = x.se.se, w = x.fi;
        if(Union(u,v)){
            mst.push_back({w, {u,v}});
            wt += w;
        }
    }

    if(mst.size() != n-1)
        cout << 0 << endl;
    else{
        cout << wt << endl;
        for(auto x : mst)
            cout << x.se.fi << " " << x.se.se << " " << x.fi << endl;
    }

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);
    // #else
    // freopen("CK.INP","r",stdin);
    // freopen("CK.OUT","w",stdout);
    #endif

    if(fopen("CK.INP", "r")){
        freopen("CK.INP","r",stdin);
        freopen("CK.OUT","w",stdout);
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}