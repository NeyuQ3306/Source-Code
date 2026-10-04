#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


/* Ý tưởng: Bài này nhớ phải sort các đỉnh của 1 thành phần liên thông tăng dần nếu lưu bằng vector
*/

const long long mod = 1e9 + 7;
int t,n,m,u;
bool found;
vector<vector<int>> adj;
vector<set<int>> adjs;
vector<bool> vis;
vector<int> deg;
vector<int> path;
vector<vector<int>> a;
vector<pair<int,int>> edge;
vector<set<int>> CC;


void bfs(int u){
    queue<int> q;
    q.push(u);
    set<int> tmp;
    tmp.insert(u);
    vis[u] = true;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int x : adj[v]){
            if(!vis[x]){
                vis[x] = true;
                tmp.insert(x);
                q.push(x);
            }
        }
    }

    CC.push_back(tmp);
}

void solve() {
    cin >> n;
    a.assign(n+1,vector<int>(n+1));
    adj.assign(n+1,{});
    vis.assign(n+1,false);
    CC.clear();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];

            if(a[i][j] && i<j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            bfs(i);
        }
    }

    cout << CC.size() << endl;
    for(int i=0; i<CC.size(); i++){
        for(int x : CC[i]) cout << x << " ";
        cout << endl;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);
    #else
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
    #endif

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