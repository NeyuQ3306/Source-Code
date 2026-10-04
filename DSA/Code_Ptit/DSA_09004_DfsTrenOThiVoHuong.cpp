#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
bool visited[1001];

void dfs(int v, vector<vector<int>> &adj){
    cout << v << " ";
    visited[v] = true;

    for(int x : adj[v]){
        if(visited[x] == false){
            dfs(x,adj);
        }
    }   
}

void solve() {
    memset(visited,false,sizeof(visited));
    int v;
    cin >> n >> m >> v;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    dfs(v, adj);
    cout << endl;
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