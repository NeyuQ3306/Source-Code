#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Hiện nay vẫn chưa có điều kiện tồn tại chu trình/đường đi Hammington cho cả
G vô hướng và có hướng
- Thuật toán liệt kê chu trình/đường đi nếu có cài đặt dựa trên quay lui tất cả các trường
hợp nên có độ phức tạp lớn O(n!) chỉ có  thể làm cho các bài với dữ kiện vào có số đỉnh nhỏ
- Ngoài cách bruteforce là backtracking ta có thể có thêm cách code khác bằng dp bitmask 
- Hoặc dùng 2 định lý sau để đánh giá xem có tồn tại chu trình hay ko:
1. Định lý Dirac
- Nếu G vô hướng có n >= 3 và deg(v) >= n/2 với mọi v thuộc V thì G chắc chắn có chu trình
Hammington (HC)
2. Định lý Ore
- Với mọi cặp đỉnh ko kề nhau u,v nếu deg(v) + deg(u) >= n thì có HC

=> 2 định lý này chỉ đánh giá điều kiện cần nếu thỏa thì chắc chắn có, nếu ko thỏa thì chưa 
chắc ko có chu trình
- Nên trong các bài lập trình kiểm tra HC, ta nên kiểm tra bằng định lý trước nếu ko thỏa thì mới kiểm tra
bằng backtracking
- Có HC thì có path nhưng ko có HC thì chưa chắc ko có path
- Nếu bài toán liệt kê mọi chu trình nếu có của đỉnh u cho trước thì dùng thêm vector<int> path để lưu
kq hoặc hay dùng là X[1001] và ta quay lui vị trí cho từng X[i]
*/

int n,m;
bool found;
vector<vector<int>> adj;
vector<bool> vis;

void Try(int i, int cnt){
    if(found) return;
    if(cnt == n){
        found = true;
        return;
    }

    for(int x : adj[i]){
        if(!vis[x]){
            vis[x] = true;
            Try(x,cnt+1); // quay lui cho vị trí cnt+1 với những khả năng là đỉnh kề của x
            vis[x] = false;
        }
    }
}

void solve() {
    cin >> n >> m;
    found = false;
    adj.assign(n+100,{});

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        vis.assign(n+100,false);
        vis[i] = true;
        Try(i,1);
        if(found) break;
    }

    cout << (found ? "1" : "0") << endl;
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