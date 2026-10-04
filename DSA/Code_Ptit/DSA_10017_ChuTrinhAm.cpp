#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Ứng dụng thuật toán Bellman Ford
- Thực hiện Bellman Ford, sau đó duyệt lại danh sách cạnh 1 lần nữa nếu có d[u] của 1 đỉnh vẫn 
bị thay đổi thì G có chu trình âm
- Với G ko liên thông ta phải kiểm tra trên tất cả thành phần liên thông mới kết luận


- Bài này nếu số đỉnh nhỏ có thể ứng dụng cả thuật toán Floyd bằng cách sau khi chạy thuật
toán Floyd kiểm tra xem có d[i][i] < 0 ko, nếu có thì G có chu trình âm
for(int i = 1; i <= n; i++){
    if(d[i][i] < 0){
        cout << "Negative cycle\n";
        return;
    }
}
*/

struct edge{
    int u,v,w;
};

int n,m;
vector<edge> canh;
vector<int> d;

bool NegCycle(int s){
    d[s] = 0;
    for(int i=1; i<=n-1; i++){
        for(auto x : canh){
            if(d[x.u] < 1e9){
                d[x.v] = min(d[x.v], d[x.u] + x.w);
            }
        }
    }

    for(auto x : canh){
        if(d[x.u] < 1e9){
            if(d[x.v] > d[x.u] + x.w){
                return true;
            }
        }
    }

    return false;
}

void solve() {
    cin >> n >> m;
    canh.clear();
    d.assign(n+1,1e9);
    
    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;

        canh.push_back((edge){x,y,z});
        // canh.push_back((edge{y,x,z}));
    }

    bool ans = false;
    for(int i=1; i<=n; i++){
        if(d[i] == 1e9){
            if(NegCycle(i)){
                ans = true;
            }
        }
    }

    cout << (ans ? "1\n" : "0\n");
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