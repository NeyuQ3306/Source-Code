#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:
- Code trâu cho subtask1: O(Q*(N+M)) 
    Với mỗi truy vấn đánh dấu cạnh e đã bị xoá (giống cạnh cầu), và chạy bfs dfs từ đỉnh u đếm số
đỉnh thuộc cùng thành phần liên thông với u 
- Code tối ưu cho cả 2 subtask: O(M+Q)
- DSU hỗ trợ thao tác thêm cạnh chứ ko hỗ trợ xoá cạnh
    sz[find(u)] cho ta biết số lượng đỉnh thuộc cùng thành phần liên thông với u
=> Đảo ngược chiều truy vấn từ xoá cạnh, bài toán trở thành thêm cạnh:
1. Đọc tất cả Q truy vấn, đánh dấu các cạnh bị xóa
2. Khởi tạo DSU với các cạnh KHÔNG bị xóa
3. Duyệt ngược Q truy vấn:
   - Lưu ans[i] = size của thành phần chứa u
   - Thêm cạnh e vào DSU (union 2 đầu cạnh e)
4. In ans[] theo thứ tự thuận

* Chú ý case 1 cạnh bị xoá nhiều lần thì graph ko đổi, nhưng khi đảo chiều truy vấn ta chỉ thêm vào
nếu biết đây là lần đầu bị xoá
=> cntDelete[i] đếm xem cạnh i bị xoá baonh lần

*/

int n,m,q;
vector<int> par,sz;
void make_set(){
    for(int i=1; i<=n; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int u){
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

void Union(int u, int v){
    u = find(u);
    v = find(v);

    if(u != v){
        if(sz[u] < sz[v]) swap(u,v);
        par[v] = u;
        sz[u] += sz[v];
    }
}

void solve() {
    cin >> n >> m >> q;
    par.assign(n+1,0);
    sz.assign(n+1,0);
    vector<pair<int,int>> canh(m+5);

    make_set();
    for(int i=1; i<=m; i++){
        int x,y;
        cin >> x >> y;

        canh[i] = {x,y};
    }

    vector<pair<int,int>> tvan(q+5);
    vector<int> cnt(m+5,0);
    for(int i=1; i<=q; i++){
        int e,u;
        cin >> e >> u;

        tvan[i] = {e,u};
        cnt[e]++;
    }

    for(int i=1; i<=m; i++){
        if(cnt[i] == 0){
            Union(canh[i].fi, canh[i].se);
        }
    }

    vector<int> ans;
    for(int i=q; i>0; i--){
        int e = tvan[i].fi;
        int u = tvan[i].se;

        ans.push_back(sz[find(u)]);
        cnt[e]--;

        if(cnt[e] == 0){
            Union(canh[e].fi, canh[e].se);
        }
    }
    reverse(ans.begin(), ans.end());
    for(int x : ans) cout << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
              
    while(t--){
       solve(); 
    }
    return 0;
}