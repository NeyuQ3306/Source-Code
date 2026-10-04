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


void dfs(int u){
    vis[u] = true;
    for(int x : adj[u]){
        if(!vis[x]) dfs(x);
    }
}

void solve1() {
    fin >> n;
    a.assign(n+10,vector<int>(n+10));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            fin >> a[i][j];
        }
    }

    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(a[i][j]) ++cnt;
        }

        fout << cnt << " ";
    }
    fout << endl;
}

void solve2() {
    fin >> n;
    a.assign(n+10,vector<int>(n+10));
    adj.assign(n+10,{});
    edge.clear();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            fin >> a[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i][j]){
                adj[i].push_back(j);
            }
        }
    }

    fout << n << endl;
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