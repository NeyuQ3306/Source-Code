#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define piii pair<int,pair<int,int>>
typedef long long ll;


/* Ý tưởng:

*/

const long long mod = 1e9 + 7;
int n,m,u;
vector<bool> vis;
vector<bool> inmst;
vector<piii> mst;
vector<vector<pair<int,int>>> canh_lthuoc;
ll wt;


void Prim(int s){
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    inmst[s] = true;
    for(auto x : canh_lthuoc[s]){
        if(!inmst[x.fi]){
            pq.push({x.se, {s,x.fi}});
        }
    }


    while(!pq.empty()){
        pair<int,pair<int,int>> t = pq.top();
        pq.pop();

        int u = t.se.fi, v = t.se.se, w = t.fi;
        if(!inmst[v]){
            wt += w;
            int a = min(u,v), b = max(u,v);
            mst.push_back({w,{a,b}});
            inmst[v] = true;


            for(auto x : canh_lthuoc[v]){
                if(!inmst[x.fi]){
                    pq.push({x.se, {v,x.fi}});
                }
            }
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

void solve() {
    cin >> n >> u;
    wt = 0;
    canh_lthuoc.assign(n+1,vector<pair<int,int>>());
    inmst.assign(n+1,false);
    mst.clear();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin >> x;

            if(x){
                canh_lthuoc[i].push_back({j,x});
            }
        }
    }

    Prim(u);
}

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("CT.INP","r",stdin);
    // freopen("CT.OUT","w",stdout);
    // // #else
    // // freopen("CK.INP","r",stdin);
    // // freopen("CK.OUT","w",stdout);
    // #endif

    // if(fopen("CK.INP", "r")){
    //     freopen("CK.INP","r",stdin);
    //     freopen("CK.OUT","w",stdout);
    // }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}