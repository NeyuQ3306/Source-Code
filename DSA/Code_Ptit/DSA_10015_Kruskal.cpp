#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

struct edge{
    int u,v,w;
};

int n,m;
vector<edge> canh;
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

    if(u == v) return false; // tao chu trinh 
    if(sz[u] < sz[v]) swap(u,v);

    par[v] = u;
    sz[u] += sz[v];
    return true;
}

void inp(){
    cin >> n >> m;
    canh.clear();
    par.resize(n+1);
    sz.resize(n+1);

    make_set();
    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;

        edge e;
        e.u = x, e.v = y, e.w = z;
        canh.push_back(e);
    }
}

void kruskal(){
    vector<edge> mst;
    int wt = 0;

    sort(canh.begin(), canh.end(), [](edge a, edge b){
        return a.w < b.w;
    });

    for(int i=0; i<canh.size(); i++){
        edge e = canh[i];
        if(Union(e.u, e.v)){
            mst.push_back(e);
            wt += e.w;
        }
    }

    cout << wt << endl;
}

void solve() {
    inp();
    kruskal();
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