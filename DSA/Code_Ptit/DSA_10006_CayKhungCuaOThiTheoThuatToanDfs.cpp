#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m,s;
vector<pair<int,int>> edge;
vector<bool> vis;
vector<pair<int,int>> st;

void dfs(int u){
    vis[u] = true;
    for(auto e : edge){
        int x = e.first, y = e.second;

        if(x == u && !vis[y]){
            st.push_back({u,y});
            dfs(y);
        }

        if(y == u && !vis[x]){
            st.push_back({u,x});
            dfs(x);
        }
    }
}

void solve() {
    cin >> n >> m >> s;
    st.clear();
    edge.clear();
    vis.assign(n+1,false);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        edge.push_back({x,y});
    }

    sort(edge.begin(), edge.end());

    dfs(s);
    if(st.size() == n-1){
        for(auto x : st) cout << x.first << " " << x.second << endl;
    }
    else cout << "-1" << endl;
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