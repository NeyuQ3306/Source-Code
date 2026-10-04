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

void dfs(int u){
    vis[u] = true;

    for(int v : adj[u]){
        if(!vis[v]){
            st.push_back({u,v});
            dfs(v);
        }
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int v : adj[u]){
            if(!vis[v]){
                vis[v] = true;
                st.push_back({u,v});
                q.push(v);
            }
        }
    }
}

void solve() {
    int x;
    cin >> x;

    if(x==1){
        cin >> n >> m >> s;
        adj.assign(n+1, set<int>());
        vis.assign(n+1,false);
        st.clear();

        for(int i=0; i<m; i++){
            int x,y;
            cin >> x >> y;

            adj[x].insert(y);
            adj[y].insert(x);
        }

        dfs(s);
        if(st.size() == n-1){
            cout << st.size() << endl;
            for(auto x : st)
                cout << x.fi << " " << x.se << endl;
        }

        else cout << 0 << endl;
    }

    else{
        cin >> n >> m >> s;
        adj.assign(n+1, set<int>());
        vis.assign(n+1,false);
        st.clear();

        for(int i=0; i<m; i++){
            int x,y;
            cin >> x >> y;

            adj[x].insert(y);
            adj[y].insert(x);
        }

        bfs(s);
        if(st.size() == n-1){
            cout << st.size() << endl;
            for(auto x : st)
                cout << x.fi << " " << x.se << endl;
        }

        else cout << 0 << endl;
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