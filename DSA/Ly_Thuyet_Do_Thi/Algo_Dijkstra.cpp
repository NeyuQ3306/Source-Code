#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Thuật toán Dijkstra - Tìm đường đi ngắn nhất từ đỉnh nguồn s tới mọi đỉnh
còn lại của đồ thị G có hướng/vô hướng nhưng ko có cạnh trọng số âm
- Cài đặt tương tự thuật toán Prim nhưng có 1 số điểm khác:
+ Ta dùng pq(hàng đợi ưu tiên) để duyệt các cạnh, danh sách kề lưu pair gồm đỉnh và trọng
số
+ Thuật toán Prim khi ta lấy đỉnh u ở đầu pq ra để duyệt danh sách kề, sẽ đẩy cạnh có trọng số
nhỏ nhất và đỉnh đuôi v chưa được xét cho vào cây
=> Quan tâm tới cạnh nào được chọn cho vào cây
+ Thuật toán Dijkstra sẽ quan tâm tới chi phí từ đỉnh nguồn cho tới đỉnh u đang được xét, với u
là đỉnh đầu hàng đợi pq
=> Quan tâm tới chi phí đi từ s tới u = trọng số cạnh (s,u) + d[s]: chi phí để tới s
=> Sau khi cập nhất chi phí tối ưu nhất cho u thì duyệt các đỉnh kề của u và cập nhật chi 
phí đi tới các đỉnh kề v đó nếu d[v] > d[u] + trọng số cạnh (u,v)

*/

int n,m,st;
vector<vector<pair<int,int>>> adj(1001);


void Dijkstra(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> d(n+1,1e9);
    d[s] = 0;
    pq.push({0,s});

    while(!pq.empty()){
        // lay ra dinh u da co chi phi it nhat di tu s
        pair<int,int> top = pq.top();
        pq.pop();

        // moi phan tu cua pq la cap {chiphi toi u tu s, dinh u}, d[u] la chi phi toi uu toi u
        int chiphi = top.first, u = top.second;
        if(chiphi > d[u]) continue; // ko xet duong di co chiphi nay nua

        // neu chiphi <= d[u] thi ta cap nhat d[v] cho cac dinh v ke u, duong di co chi phi nay cho d[u]
        // neu ko roi vao cau lenh if thi chac chan chiphi = d[u] vi neu chiphi < d[u] thi u phai duoc duyet voi vai tro dinh ke roi
        for(auto it : adj[u]){
            int v = it.first, w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }

    for(int i=1; i<=n; i++) cout << d[i] << " ";
}

void solve() {
    cin >> n >> m >> st;
    adj.assign(n+1,{});

    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;

        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    Dijkstra(st);
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