#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Thuật toán Floyd - Tìm đường đi ngắn nhất giữa mọi cặp đỉnh (s,t)
- Thuật toán này tương tự cách suy nghĩ bruteforce ta duyệt 3 vòng for k,i,j với k là đinh trung gian
để tìm d[i][j] chi phí tối ưu nhất đi từ i tới j
- Độ phức tạp O(V^3) nên phù hợp với các bài toán G có số đỉnh nhỏ và nhiều truy vấn
- Sử dụng được cho cả G vô hướng / có hướng, có cạnh trọng số âm và ko có chu trình âm
- Floyd có thể ứng dụng trong kiểm tra G có chu trình âm hay ko, bằng cách sau khi chạy thuật
toán Floyd kiểm tra xem có d[i][i] < 0 ko, nếu có thì G có chu trình âm
- Sau khi chạy xong các hàm thuật toán ta sẽ có chi phí tối ưu từ 1 đỉnh tới mọi
đỉnh còn lại (Dijkstra/BellmanFord) thì chỉ cần truy vết ngược lại là được
- Đối với thuật toán Floyd sẽ phải dùng ma trận 2 chiều để lưu:
Nếu cập nhật d[v] qua d[u] và đỉnh k thì par[u][v] = par[k][v]
Với par[i][j]: đỉnh liền trước j trên đường đi từ i->j đây là cách lâu previous
hoặc nếu muốn par[i][j]: đỉnh kế tiếp i đi tới trên đường đi từ i->j thì khi cập nhật gán:
par[u][v] = par[u][k]
*/

int n;
vector<vector<ll>> d;
vector<vector<int>> ts, Next;

void Floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][j] > d[i][k] + d[k][j] && d[i][k] < 1e9 && d[k][j] < 1e9){
                    d[i][j] = d[i][k] + d[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }

    int s = -1, t = -1;
    int max_d = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i != j && d[i][j] != 1e9 && d[i][j] > max_d){
                max_d = d[i][j];
                s = i, t = j;
            }
        }
    }

    if(s == -1) cout << "0" << endl;
    else{
        cout << s << " " << t << " " << max_d << endl;
        vector<int> path;
        while(s != t){
            path.push_back(s);
            s = Next[s][t];
        }

        path.push_back(t);
        for(int x : path) cout << x << " ";
        cout << endl;
    }

}


void solve(){
    // ma tran trong so
    cin >> n;
    d.assign(n+1,vector<ll>(n+1,1e9));
    ts.assign(n+1,vector<int>(n+1,0));
    Next.assign(n+1,vector<int>(n+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> ts[i][j];

            if(i == j) d[i][j] = 0;

            if(ts[i][j] > 0 && ts[i][j] != 10000){
                d[i][j] = ts[i][j];
                Next[i][j] = j;
            }

            else{
                Next[i][j] = -1;
            }
        }
    }

    Floyd();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}