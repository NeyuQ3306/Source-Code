#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Cấu trúc dữ liệu các tập hợp rời nhau DSU cho phép ta thực hiện 2 thao tác
find(u): tìm gốc của cây chứa đỉnh u và Union(a,b) hợp 2 cây chứa a,b thành 1 với độ phức
tạp O(1)
- Do CTDL DSU ko được cài đặt sẵn ta có thể tự cài đặt bằng 3 hàm chính make_set, find và union 
hoặc cấu trúc struct DSU

- Ứng dụng của DSU trong các bài toán: Kiểm tra chu trình, đếm số lượng thành phần liên thông,
tìm cây khung nhỏ nhất (MST), ....
*/

// Struct
Struct DSU{
    vector<int> par,sz;
    DSU(int n){
        par.resize(n+1);
        sz.resize(n+1,1);

        for(int i=1; i<=n; i++) par[i] = i;
    }

    int find(int u){
        if(u == par[u]) return u;
        return par[u] = find(par[u]);
    }

    void Union(int u, int v){
        int root_u = find(u);
        int root_v = find(v);

        if(root_u == root_v) return;
        if(root_u < root_v) swap(root_u,root_v)

        par[root_v] = root_u;
        sz[root_u] += sz[root_v];
    }
}

// Tự cài đặt bằng 3 hàm riêng biệt tương tự


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