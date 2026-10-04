#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Mỗi nhóm bạn là 1 đồ thị đầy đủ
- Ta xét từng thành phần và check xem nó có phải complete graph ko, nếu có số cạnh = n*(n-1)/2 với
n là số đỉnh thì thỏa mãn
VD: X-Y, Y-Z thì phải có cạnh nối X-Z mới là đồ thị đầy đủ
*/

int n,m;
vector<int> par, sz;
vector<bool> vis;
vector<long long> edge;

void make_set(){
    for(int i=1; i<=n; i++){
        par[i] = i;
        sz[i] = 1;
        edge[i] = 0;
    }
}

int find(int u){
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

void Union(int u, int v){
    int ru = find(u);
    int rv = find(v);

    // đọc vào từng cạnh, nếu 2 đỉnh mút đã cùng 1 cây thì số cạnh của cây đấy tăng thêm 1
    if(ru == rv){
        edge[ru]++; // cạnh trong cùng component
        return;
    }

    // nếu 2 đỉnh thuộc 2 cây khác nhau thì nối cây bé vào cây to, số cạnh bằng tổng số cạnh 2 cây + 1 cạnh nối
    if(sz[ru] < sz[rv]) swap(ru, rv);

    par[rv] = ru;
    sz[ru] += sz[rv];
    edge[ru] += edge[rv] + 1;
}

void solve(){
    cin >> n >> m;

    par.assign(n+1,0);
    sz.assign(n+1,0);
    edge.assign(n+1,0);

    make_set();

    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        Union(u,v);
    }

    for(int i=1; i<=n; i++){
        if(find(i) == i){ // root
            long long k = sz[i];
            long long e = edge[i];

            if(e != k * (k - 1) / 2){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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