#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m,v;
bool visited[1001];

void bfs(int v, vector<vector<int>> adj){
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        cout << u << " ";
        for(int x : adj[u]){
            if(visited[x] == false){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

void solve() {
    memset(visited,false,sizeof(visited));
    cin >> n >> m >> v;
    vector<vector<int>> adj(n+1);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    bfs(v,adj);
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