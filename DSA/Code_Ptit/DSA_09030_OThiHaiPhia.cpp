#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
vector<vector<int>> adj;
vector<int> color;

bool bfs(int u){
    color[u] = 0;
    queue<int> q;
    q.push(u);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int x : adj[v]){
            if(color[x] == -1){
                color[x] = 1 - color[v];
                q.push(x);
            }
            
            else if(color[x] == color[v]) return false;
        }
    }

    return true;
}

void solve() {
    cin >> n >> m;
    adj.assign(n+1,{});
    color.assign(n+1,-1);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        if(color[i] == -1){
            if(!bfs(i)){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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