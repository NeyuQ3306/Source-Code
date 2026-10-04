#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;


/* Ý tưởng:

*/

const long long mod = 1e9 + 7;
int n,m,u,s,t;
vector<set<int>> adj;
vector<set<int>> adjs;
vector<bool> vis;
vector<int> ideg;
vector<int> odeg;
vector<int> path;
vector<vector<int>> ke;
vector<vector<int>> lt;
vector<vector<int>> ts;
vector<pair<int,int>> st;
set<pair<int,int>> edge;
vector<pair<int,pair<int,int>>> canh;
vector<vector<int>> CC;
vector<int> tmp;
vector<int> par;

void dfs(int u){
    vis[u] = true;
    for(int x : adj[u]){
        if(!vis[x]){
            par[x] = u;
            dfs(x);
        }
    }
}

void solve() {
    int x;
    cin >> x;

    if(x==1){
        cin >> n >> s >> t;
        ke.assign(n+1,vector<int>(n+1));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> ke[i][j];
            }
        }

        int cnt = 0;
        for(int k=1; k<=n; k++){
            if(ke[s][k] && ke[k][t])
                ++cnt;
        }

        cout << cnt << endl;
    }

    else{
        cin >> n >> s >> t;
        adj.assign(n+1, set<int>());
        ke.assign(n+1,vector<int>(n+1));
        par.assign(n+1,0);
        path.clear();
        vis.assign(n+1,false);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> ke[i][j];

                if(ke[i][j]){
                    adj[i].insert(j);
                }
            }
        }

        dfs(s);

        if(!vis[t])
            cout << 0 << endl;
        else{
            while(t != s){
                path.push_back(t);
                t = par[t];
            }
            path.push_back(s);

            reverse(path.begin(), path.end());

            for(int x : path)
                cout << x << " ";

            cout << endl;
        }
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

    if(fopen("TK.INP", "r")){
        freopen("TK.INP","r",stdin);
        freopen("TK.OUT","w",stdout);
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}