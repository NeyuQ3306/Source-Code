#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: G là cây khi và chỉ khi G vô hướng, liên thông và ko có chu trình
- Các tính chất quan trọng:
1️⃣ Giữa hai đỉnh bất kỳ chỉ có đúng 1 đường đi đơn
2️⃣ Nếu thêm 1 cạnh vào cây → xuất hiện chu trình
3️⃣ Nếu xóa 1 cạnh của cây → đồ thị bị tách thành 2 thành phần
4️⃣ Các điều kiện tương đương của cây: Đồ thị G là cây khi:
Liên thông và |E| = n − 1
Không có chu trình và |E| = n − 1
Liên thông và xóa bất kỳ cạnh nào cũng làm mất liên thông
*/

int n;
vector<vector<int>> adj(1001);
vector<int> deg(1001);
vector<bool> vis(1001);

void dfs(int u){
    vis[u] = true;
    for(int x : adj[u]){
        if(!vis[x]) dfs(x);
    }
}

void solve() {
    cin >> n;
    adj.assign(n+10,{});
    deg.assign(n+10,0);
    vis.assign(n+10,false);
    for(int i=0; i<n-1; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);

        deg[x]++;
        deg[y]++;
    }
    
    int start = -1;
    for(int i=1; i<=n; i++){
        if(deg[i] != 0){
            start = i;
            break;
        }
    }

    bool lt = true;
    if(start != -1){
        dfs(start);
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                lt = false;
                break;
            }
        }
    }

    if(lt) cout << "YES\n";
    else cout << "NO\n";
    
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