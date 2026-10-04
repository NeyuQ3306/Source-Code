#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


/* Ý tưởng:

*/

const long long mod = 1e9 + 7;
int t,n,m,u;
bool found;
vector<vector<int>> adj;
vector<set<int>> adjs;
vector<bool> vis;
vector<int> deg;
vector<int> path;
vector<vector<int>> a;
vector<pair<int,int>> edge;
vector<vector<int>> CC;
vector<vector<int>> res;

void Hamilton(){
    if(path.size() == n){
        if(a[path.back()][u]){
            path.push_back(u);
            res.push_back(path);
            path.pop_back();
        }
        return;
    }

    for(int j=1; j<=n; j++){
        if(!vis[j] && a[path.back()][j]){
            vis[j] = true;
            path.push_back(j);

            Hamilton();

            path.pop_back();
            vis[j] = false;
        }
    }
}

void solve() {
    cin >> n >> u;

    a.assign(n+1, vector<int>(n+1));
    vis.assign(n+1,false);
    path.clear();
    res.clear();

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> a[i][j];

    path.push_back(u);
    vis[u] = true;

    Hamilton();

    if(res.size()){
        cout << res.size() << "\n";
        for(auto &v : res){
            for(int x : v) cout << x << " ";
            cout << "\n";
        }
    }
    else cout << "0\n";
}

int main() {
    // // #ifndef ONLINE_JUDGE
    // // freopen("CT.INP","r",stdin);
    // // freopen("CT.OUT","w",stdout);
    // // #else
    // // freopen("CT.INP","r",stdin);
    // // freopen("CT.OUT","w",stdout);
    // #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;

    int t = 1;

    while(t--){
        solve();
    }
    return 0;
}