#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Thuật toán Bellman Ford - Tìm đường đi ngắn nhất từ 1 đỉnh s tới mọi đỉnh còn lại
- Áp dụng được cho G có cạnh trọng số âm nhưng ko áp dụng được nếu G có chu trình âm
- Thuật toán: Với G có n đỉnh và m cạnh độ phức tạp là O(n*m) tệ hơn Dijkstra nhưng khắc phục
được nhược điểm nếu G có cạnh trọng số âm 
- Ban đầu ta cho d[u]: chi phí tối ưu từ s tới u là vô cùng, duyệt n-1 lần với mỗi lần ta duyệt
tất cả các cạnh
VD: Duyệt cạnh (u,v,w) nếu d[u] < vô cùng và d[v] > d[u] + w thì cập nhật d[v], cứ lặp lại cho tới
hết các cạnh như thế. Có thể ko cần đủ n-1 bước lặp đã ra được đường đi ngắn nhất

- Chú ý cả Bellman Ford và Dijkstra đều chạy được cho cả G có hướng/ vô hướng, với G vô hướng thì
danh sách cạnh sẽ phải lưu cả cạnh ngược thì số lượng cạnh là 2E độ phức tạp nhìn chung ko thay đổi
*/

struct edge{
    int u,v,w;
};

int n,m,st;
vector<edge> canh;
vector<int> d;

void inp(){
    cin >> n >> m >> st;
    canh.clear();
    d.assign(n+1,1e9);

    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;

        edge e;
        e.u = x, e.v = y, e.w = z;

        edge k;
        k.u = y, k.v = x, k.w = z;
        canh.push_back(e);
        canh.push_back(k);
    }
}

void Bellman_Ford(int s){
    d[s] = 0;
    for(int i=1; i<=n-1; i++){
        for(auto e : canh){
            int x = e.u, y = e.v, z = e.w;
            if(d[x] < 1e9){
                d[y] = min(d[y], d[x] + z);
            }
        }
    }

    for(int i=1; i<=n; i++) cout << d[i] << " ";
}

void solve() {
    inp();
    Bellman_Ford(st);
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