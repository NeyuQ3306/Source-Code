#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/


int n,m,u;
vector<vector<int>> adj;
vector<set<int>> adjs;
vector<bool> vis;
vector<int> deg;
vector<int> path;
vector<vector<int>> a;
vector<pair<int,int>> edge;
vector<vector<int>> CC;
vector<int> tmp;

void dfs(int u){
    vis[u] = true;
    tmp.push_back(u);
    for(int x : adj[u]){
        if(!vis[x]) dfs(x);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    ifstream fin("TK.INP");
    ofstream fout("TK.OUT");


    // ifstream fin("CT.INP");
    // ofstream fout("CT.OUT");

    fin >> n;

    a.assign(n+10, vector<int>(n+10,0));
    adj.assign(n+10,{});
    vis.assign(n+10,false);


    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            fin >> a[i][j];
            if(a[i][j]){
                adj[i].push_back(j);
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            tmp.clear();
            dfs(i);
            CC.push_back(tmp);
        }
    }
    
    fout << CC.size() << endl;
    for(int i=0; i<CC.size(); i++){
        sort(CC[i].begin(), CC[i].end());
        for(int x : CC[i]) fout << x << " ";
        fout << endl;
    }        
    return 0;
}