#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
vector<vector<int>> adj(1001);
vector<bool> vis(1001);
vector<int> degree(1001); // dem bac cua dinh i

void dfs(int v){
    vis[v] = true;
    for(int x : adj[v]){
        if(!vis[x]) dfs(x);
    }
}

void solve() {
    cin >> n >> m;
    adj.assign(n+1,{});
    vis.assign(n+1,false);
    degree.assign(n+1,0);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }

    // Kiem tra tinh lien thong
    dfs(1);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cout << "0" << endl;
            return;
        }
    }

    // Kiem tra so luong bac chan, bac le
    int bc = 0, bl = 0;
    for(int i=1; i<=n; i++){
        if(degree[i] % 2 == 0) ++bc;
        else ++bl;
    }

    if(bc == n) cout << "2" << endl;
    else if(bl <= 2) cout << "1" << endl;
    else cout << "0" << endl;
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