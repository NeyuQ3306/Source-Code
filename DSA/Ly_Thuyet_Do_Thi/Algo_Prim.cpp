#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Thuật toán Prim - Cây khung nhỏ nhất
- Ta duy trì mảng taken gồm n phần tử tương ứng với n đỉnh, taken[u] = true nếu đỉnh u
đã nằm trong cây khung và ngược lại taken[u] = false nếu chưa sử dụng
- Sử dụng 1 priority_queue để lưu các pair<int,int> gồm p.first = w  và p.second = v
với (u,v) là 1 cạnh có trọng số w
- Thuật toán Prim bắt đầu từ 1 đỉnh s bất kì:
B1: Nạp đỉnh s vào cây khung và các cạnh liên thuộc của s vào pq (hàng đợi)
+ taken[s] = true
+ Ta lưu danh sách kề của 1 đỉnh gồm đỉnh kề và trọng số, duyệt các cạnh liên thuộc của s
vào pq

B2: Lặp cho tới khi hết các đỉnh hoặc pq đã rỗng
while(!pq.empty()){
    // lấy ra cạnh có trọng số nhỏ nhất - đỉnh hàng đợi
    pair<int,int> e = pq.top(), pq.pop();
    int v = e.second, w = e.first;
    // Kiểm tra xem đỉnh v đã được sử dụng chưa, nếu chưa mới thêm vào cây
    if(!taken[v]){
        <thêm vào cây>
        taken[v] = true;
        <duyệt các cạnh liên thuộc để cho vào hàng đợi>   
    }
} 

B3: In kết quả nếu số cạnh của cây = n-1 thì có cây khung
*/

int n,m;
vector<vector<pair<int,int>>> adj;
vector<bool> taken;

void Prim(int s){
    // B1
    taken[s] = true;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto x : adj[s]){
        if(!taken[x.first]){
            pq.push({x.second, x.first});
        }
    }

    // B2
    int wt = 0, cnt = 0;
    while(!pq.empty()){
        pair<int,int> e = pq.top();
        pq.pop();
        int v = e.second, w = e.first;

        if(!taken[v]){
            ++cnt;
            wt += w;
            taken[v] = true;

            for(auto x : adj[v]){
                if(!taken[x.first]){
                    pq.push({x.second, x.first});
                }
            }
        }
    }

    // B3
    if(cnt == n-1) cout << wt << endl;
    else cout << "-1" << endl;
}

void solve() {
    cin >> n >> m;
    adj.assign(n+1,{});
    taken.assign(n+1,false);

    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;

        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    Prim(1);
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