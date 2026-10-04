#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;


/* Ý tưởng: Bài này test mẫu sai phải có 2 chu trình Hamilton
- Nên code bằng ma trận kề cho đơn giản
*/

const long long mod = 1e9 + 7;
int n,m,u;
vector<set<int>> adjs;
vector<bool> vis;
vector<int> ideg;
vector<int> odeg;
vector<int> deg;
vector<vector<int>> ke;
vector<vector<int>> lt;
vector<vector<int>> ts;
set<pair<int,int>> edge;
vector<pair<int,pair<int,int>>> canh;
vector<vector<int>> CC;
vector<int> EC;
vector<int> path;
vector<vector<int>> res;


void Hamilton(){
    if(path.size() == n){
        if(ke[path.back()][u]){
            path.push_back(u);
            res.push_back((path));
            path.pop_back();
        }

        return;
    }

    for(int i=1; i<=n; i++){
        if(!vis[i] && ke[path.back()][i]){
            path.push_back(i);
            vis[i] = true;

            Hamilton();
            vis[i] = false;
            path.pop_back();
        }
    }

}

void solve(){
    cin >> n >> m >> u;
    ke.assign(n+1,vector<int>(n+1,0));
    vis.assign(n+1,false);
    res.clear();
    path.clear();

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        ke[x][y] = ke[y][x] = 1;
    }

    path.push_back(u);
    vis[u] = true;
    Hamilton();

    if(res.size() == 0)
        cout << 0 << endl;
    else{
        cout << res.size() << endl;
        for(int i=0; i<res.size(); i++){
            for(int x : res[i])
                cout << x << " ";

            cout << endl;
        }
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);
    // #else
    // freopen("CK.INP","r",stdin);
    // freopen("CK.OUT","w",stdout);
    #endif

    if(fopen("CT.INP", "r")){
        freopen("CT.INP","r",stdin);
        freopen("CT.OUT","w",stdout);
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}