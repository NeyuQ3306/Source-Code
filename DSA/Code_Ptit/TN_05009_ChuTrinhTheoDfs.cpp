#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Bài này chú ý ở bước truy ngược lại chu trình, có thể chu trình khi gọi
dfs(1) nó ko quay lại 1 thì wa, nên ta chỉ gán s,t khi s = 1
- Điều kiện tồn tại chu trình:
Th1, Chu trình bất kì, dfs từ đỉnh bất kì nếu G vô hướng liên thông: vis[x] && x != par[v]
Th2, Chu trình đi qua đỉnh bắt buộc s, dfs(s) tồn tại chu trình nếu: x == s && x != par[v]
*/

int n,m,s,t;
vector<vector<int>> adj(1001);
vector<bool> vis(1001);
int par[1001];
vector<int> path;
bool flag;

void dfs(int v){
    if(flag) return;
    vis[v] = true;

    for(int x : adj[v]){
        if(!vis[x]){
            par[x] = v;
            // if(dfs(x)) return true;
            dfs(x);
        }
        else if(x == 1 && x != par[v]){
            path.push_back(x);
            int end = v;
            while(end != 1){
                path.push_back(end);
                end = par[end];
            }

            path.push_back(1);
            reverse(path.begin(), path.end());
            for(int x : path) cout << x << " ";
            cout << endl;

            flag = true;
            return;
        }
    }
}

void solve() {
    cin >> n >> m;
    flag = false;
    adj.assign(n+1,{});
    vis.assign(n+1,false);
    path.clear();
    memset(par,0,sizeof(par));

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++) sort(adj[i].begin(), adj[i].end());
        
    dfs(1);

    if(!flag) cout << "NO\n";
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