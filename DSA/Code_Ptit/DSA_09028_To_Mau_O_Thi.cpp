#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Với số đỉnh nhỏ ta quay lui tất cả trường hợp xem có tô các đỉnh ko kề nhau màu khác nhau
được ko sao cho ko quá m màu
- Với mỗi đỉnh miền giá trị color c từ 1->m, color[u] = c nếu ko có đỉnh kề nào của u có màu c
- Dừng lại khi duyệt hết đỉnh hoặc số màu đã vượt quá m

*/

int n,m,k;
vector<vector<int>> adj;
vector<int> color;

bool check(int u, int c){
    // check xem các đỉnh kề của u có đỉnh nào bị trùng màu ko
    for(int x : adj[u]){
        if(color[x] == c) return false;
    }

    return true;
}

bool Try(int u){
    if(u > n) return true;

    for(int c=1; c<=k; c++){
        if(check(u,c)){
            color[u] = c;
            // nếu có thể tô màu hết các đỉnh ở sau mới return true, nếu có đỉnh ko tô được màu thì hàm Try = false
            if(Try(u+1)) return true;
            color[u] = 0;
        }
    }

    // chưa đủ đỉnh mà đã dùng hết màu thì return false luôn
    return false;
}

void solve() {
    cin >> n >> m >> k;
    adj.assign(n+1,{});
    color.assign(n+1,0);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << (Try(1) ? "YES\n" : "NO\n");
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