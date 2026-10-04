#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


/* Ý tưởng: Bài toán kiểm tra tính liên thông mạnh, ko liên thông mạnh nhưng liên thông yếu
- Ta kiểm tra tính liên thông mạnh bằng Kosaraju: cnt SCC = 1 => in 1
- Kiếm tra đồ thị G có hướng liên thông yếu nếu đồ thị vô hướng nền là liên thông => in 2
- Trường hợp còn lại in ra 0

*/

const long long mod = 1e9 + 7;
int t,n,m,u;
bool found;
vector<vector<int>> adj, adjr;
vector<set<int>> adjs;
vector<bool> vis;
vector<int> deg;
vector<int> path;
vector<vector<int>> a;
vector<pair<int,int>> edge;
vector<set<int>> CC;
stack<int> topo;

// dfs normal
void dfs1(int u){
    vis[u] = true;

    for(int x : adj[u]){
        if(!vis[x])
            dfs1(x);
    }
}


// in SCC
void dfs2(int u){
    vis[u] = true;

    for(int x : adjr[u]){
        if(!vis[x])
            dfs2(x);
    }
}

// TopoSort
void TopoSort(int u){
    vis[u] = true;

    for(int x : adj[u]){
        if(!vis[x])
            TopoSort(x);
    }

    topo.push(u);
}

// Kosaraju
bool check_lt_manh(){
    vis.assign(n+1,false);

    for(int i=1; i<=n; i++){
        if(!vis[i])
            TopoSort(i);
    }

    vis.assign(n+1,false);
    int cnt = 0;
    while(!topo.empty()){
        int v = topo.top();
        topo.pop();

        if(!vis[v]){
            ++cnt;
            dfs2(v);
        }
    }

    return cnt == 1;
}

bool check_ko_lt_manh_nhung_lt_yeu(){
    vis.assign(n+1,false);
    adj.assign(n+1,{});

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n;j++){
            if(a[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    dfs1(1);
    for(int i=1; i<=n; i++){
        if(!vis[i]) return false;
    }

    return true;
}

void solve() {
    cin >> n;
    a.assign(n+5, vector<int>(n+5));
    adj.assign(n+1,{});
    adjr.assign(n+1,{});
    vis.assign(n+5,false);


    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];

            // do thi co huong
            if(a[i][j]){
                adj[i].push_back(j);
                adjr[j].push_back(i);
            }
        }
    }

    int ans = 0;
    // ktra tinh lien thong manh bang thuat toan Kosaraju
    if(check_lt_manh()) ans = 1;
    // ktra bang do thi vo huong nen co lien thong hay ko
    else if(check_ko_lt_manh_nhung_lt_yeu()) ans = 2;

    cout << ans << endl;
}

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("CT.INP","r",stdin);
    // freopen("CT.OUT","w",stdout);
    // #else
    // freopen("TK.INP","r",stdin);
    // freopen("TK.OUT","w",stdout);
    // #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;

    int t = 1;

    while(t--){
        solve();
    }
    return 0;
}