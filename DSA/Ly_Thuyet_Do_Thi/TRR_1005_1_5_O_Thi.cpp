#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

ifstream fin("DT.INP");
ofstream fout("DT.OUT");


// ifstream fin("CT.INP");
// ofstream fout("CT.OUT");


int n,m,u;
vector<vector<int>> adj;
vector<set<int>> adjs;
vector<bool> vis;
vector<int> deg;
vector<int> path;
vector<vector<int>> a;
vector<pair<int,int>> edge;


// void dfs(int u){
//     vis[u] = true;
//     for(int x : adj[u]){
//         if(!vis[x]) dfs(x);
//     }
// }

void solve1() {
    fin >> n >> m;
    a.assign(n+10,vector<int>(n+10));
    edge.assign(n+10,{});
    deg.assign(n+10,0);

    for(int i=0; i<m; i++){
        int x,y;
        fin >> x >> y;

        deg[x]++;
        deg[y]++;
    }

    for(int i=1; i<=n; i++){
        fout << deg[i] << " ";
    }
    fout << endl;
}

void solve2() {
    fin >> n >> m;
    a.assign(n+10,vector<int>(n+10));
    adj.assign(n+10,{});
    edge.clear();

    fout << n << endl;
    for(int i=0; i<m; i++){
        int x,y;
        fin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        fout << adj[i].size() << " ";
        for(int x : adj[i]) fout << x << " ";
        fout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    fin >> t;

    if(t == 1){
        solve1();
    }

    else if(t == 2){
        solve2();
    }
    
    return 0;
}