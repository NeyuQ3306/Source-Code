#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define sz size
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: Các bài toán di chuyển bản chất là bfs trên đồ thị
- Chỉ cần xác định được trạng thái hiện tại, điều kiện dừng, cách duyệt đỉnh kề là giải quyết
được bài toán
*/
int n,m;
int a[1005][1005];
bool vis[1005][1005];
bool ok;

void bfs(){
    // pair lưu {vị trí đỉnh đang xét, số bước để tới đỉnh đang xét}
    queue<pair<pair<int,int>, int>> q;
    memset(vis, false, sizeof(vis));

    q.push({{1,1}, 0});
    vis[1][1] = true;

    while(!q.empty()){
        auto t = q.front(); q.pop();

        int i = t.fi.fi;
        int j = t.fi.se;
        int step = t.se;

        // điều kiện dừng
        if(i == n && j == m){
            cout << step << '\n';
            ok = true;
            return;
        }

        // duyệt đỉnh kề
        int jump = a[i][j];

        // xuống
        if(i + jump <= n && !vis[i + jump][j]){
            vis[i + jump][j] = true;
            q.push({{i + jump, j}, step + 1});
        }

        // sang phải
        if(j + jump <= m && !vis[i][j + jump]){
            vis[i][j + jump] = true;
            q.push({{i, j + jump}, step + 1});
        }
    }
}

void solve() {
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }

    ok = false;
    bfs();
    if(!ok) cout << -1 << endl;
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