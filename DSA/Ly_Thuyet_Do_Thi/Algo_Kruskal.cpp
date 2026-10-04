#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Thuật toán Kruskal tìm cây khung nhỏ nhất MST
Ta có 3 bước chính:
B1: Khởi tạo MST rỗng, WT = 0 (tổng trọng số của cây khung)
B2: Sort danh sách cạnh tăng dần theo trọng số (dùng struct hoặc tuple để lưu cạnh)
B3: Lặp duyệt danh sách cạnh kiểm tra nếu thêm cạnh e vào MST ko tạo thành chu trình thì
thêm vào, kiểm tra tạo thành chu trình hay ko bằng DSU
*/

struct edge{
    int u,v,w;
};

int n,m;
vector<int> par(1001), sz(1001);
vector<edge> canh(m);


void make_set(){
    for(int i=1; i<=n; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int u){
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

bool Union(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return false; // ko the them canh (u,v) vao mst
    if(sz[u] < sz[v]) swap(u,v);

    par[v] = u;
    sz[u] += sz[v];
    return true;
}

void inp(){
    cin >> n >> m;
    par.resize(n+1,0);
    sz.resize(n+1,1);
    
    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;

        edge e;
        e.u = x, e.v = y, e.w = z;
        canh.push_back(e);
    }
}

void kruskal(){
    // b1: khoi tao
    vector<edge> mst;
    int wt = 0;

    // b2: sort danh sach canh
    sort(canh.begin(), canh.end(), [](edge a, edge b){
        return a.w < b.w;
    });

    // b3: lap
    for(int i=0; i<canh.size(); i++){
        if(mst.size() == n-1) break;

        edge e = canh[i];
        // co the them canh e vao mst
        if(Union(e.u, e.v)){
            mst.push_back(e);
            wt += e.w;
        }
    }

    // cout << mst.size() << endl;

    if(mst.size() < n-1) cout << "Ko lien thong\n";
    else if(mst.size() > n-1) cout << "Co chu trinh\n";
    else cout << wt << endl;

    for(auto x : mst){
        cout << x.u << " " << x.v << " " << x.w << endl;
    }
}

void solve() {
    inp();
    make_set();
    kruskal();
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