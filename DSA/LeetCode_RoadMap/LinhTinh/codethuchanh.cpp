#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/
int n,m,wt;
bool check = false;
int cnt_c_mst = 0;
vector<int> mst;
vector<vector<pair<int,int>>> adj;
vector<bool> inmst;

void Prim(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,s});
    inmst[s] = true;

    for(auto x : adj[s]){
        if(!inmst[x.fi]){
            q.push({x.se, x.fi});
        }
    }

    while(!q.empty()){
        auto t = q.top();
        q.pop();

        int u = t.se, w = t.fi;
        if(!inmst[u]){
            ++cnt_c_mst;
            wt += w;
            inmst[u] = true;
            
            for(auto x : adj[u]){
                if(!inmst[x.fi]){
                    q.push({x.se, x.fi});
                }
            }
        }
    }

    if(cnt_c_mst == n-1) check = true;
}

void solve() {
    cin >> n >> m;
    inmst.assign(n+1, false);
    adj.assign(n+1,{});
    mst.clear();

    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;

        adj[x].push_back({y,z});
    }


    Prim(1);
    ll minv = wt;
    vector<int> firstmst = mst

    int cnt = 0;
    for(int i=1; i<=n; i++){
        inmst.assign(n+1,false);
        wt = 0;
        cnt_c_mst = 0;
        check = false;
        Prim(i);
        if(check){
            if(wt == minv) ++cnt;
        }
    }

    cout << minv << " " << cnt << endl;
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