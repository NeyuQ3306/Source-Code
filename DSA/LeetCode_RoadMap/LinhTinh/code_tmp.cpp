#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

typedef long long ll;


/* Ý tưởng: Đối với các thuật toán tìm đường đi ngắn nhất muốn in ra đường đi
cho chi phí tối ưu thì duy trì thêm mảng par
- Mỗi khi cập nhật chi phí tốt hơn cho 1 đỉnh v kề với u thì cho
par[v] = u;
- Sau khi chạy xong các hàm thuật toán ta sẽ có chi phí tối ưu từ 1 đỉnh tới mọi
đỉnh còn lại (Dijkstra/BellmanFord) thì chỉ cần truy vết ngược lại là được
- Đối với thuật toán Floyd sẽ phải dùng ma trận 2 chiều để lưu
*/

const long long mod = 1e9 + 7;
int n,s,t;
vector<vector<pii>> adj;
vector<ll> d;
vector<int> par;

void find_path(){
    if(d[t] == 1e9)
        cout << 0 << endl;
    else{
        int tmp = t;
        vector<int> path;
        while(t != s){
            path.push_back(t);
            t = par[t];
        }

        path.push_back(s);
        reverse(path.begin(), path.end());

        cout << d[tmp] << endl;
        for(int x : path)
            cout << x << " ";
        cout << endl;
    }
}

void Dijkstra(int s){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
    d[s] = 0;

    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();

        int chiphi = top.fi, v = top.se;
        if(chiphi > d[v]) continue;

        for(auto x : adj[v]){
            if(d[x.fi] > d[v] + x.se){
                d[x.fi] = d[v] + x.se;
                par[x.fi] = v;
                pq.push({d[x.fi], x.fi});
            }
        }
    }

    find_path();
}

void solve(){
    cin >> n >> s >> t;
    adj.assign(n+1,{});
    d.assign(n+1,1e9);
    par.assign(n+1,-1);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin >> x;

            if(x > 0 && x != 10000){
                adj[i].push_back({j,x});
                adj[j].push_back({i,x});
            }
        }
    }

    Dijkstra(s);
}


int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("CT.INP","r",stdin);
    // freopen("CT.OUT","w",stdout);
    // #endif

    // if(fopen("DN.INP", "r")){
    //     freopen("DN.INP","r",stdin);
    //     freopen("DN.OUT","w",stdout);
    // }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}