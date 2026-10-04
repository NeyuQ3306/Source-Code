#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Bài này ta có thể code bằng cả dfs/bfs(thuật toán kahn)
- dfs dễ cài đặt, ngắn gọn còn bfs thì trực quan dễ hiểu hơn
*/

int n,m,cnt;
vector<vector<int>> adj(1001);
vector<int> color(1001);
vector<int> indeg(1001);
vector<int> par(1001);

bool kahn(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();
        ++cnt;

        for(int x : adj[v]){
            --indeg[x];
            if(indeg[x] == 0) q.push(x);
        }
    }

    return cnt == n;
}

bool dfs(int u){
    color[u] = 1;
    for(int v : adj[u]){
        if(color[v] == 0){
            par[v] = u;
            if(dfs(v)) return true;
        }
        else if(color[v] == 1) return true;
    }
    color[u] = 2;
    return false;
}

void solve() {
    cin >> n >> m;
    cnt = 0;
    adj.assign(n+100,{});
    color.assign(n+100,0);
    indeg.assign(n+100,0);
    par.assign(n+100,0);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        indeg[y]++;
    }

    // if(!kahn()) cout << "YES\n";
    // else cout << "NO\n";

    for(int i=1; i<=n; i++){
        if(color[i] == 0){
            if(dfs(i)){
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
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