#include <bits/stdc++.h>
using namespace std;

ifstream fin("TK.INP");
ofstream fout("TK.OUT");

int n;
vector<vector<int>> adj;
vector<int> dinhtru;
bool vis[1001];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]) dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fin >> n;

    adj.assign(n+1,{});

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            fin >> x;

            if(x && i < j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    memset(vis,false,sizeof(vis));

    int k = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            k++;
        }
    }

    for(int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));

        vis[i] = true;

        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(!vis[j]){
                dfs(j);
                cnt++;
            }
        }

        if(cnt > k) dinhtru.push_back(i);
    }

    fout << dinhtru.size() << "\n";

    for(int x : dinhtru){
        fout << x << " ";
    }

    fout << "\n";

    return 0;
}