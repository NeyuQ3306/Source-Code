#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;


/* Ý tưởng: Chú ý đoạn cộng vào sw và pop cần lưu lại đỉnh cuối trước khi push vào
hoặc là tính toán trước và pop trước khi push
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
vector<int> ans;
ll min_w;
ll sw = 0;

void Hamilton(){
    if(sw > min_w)
        return;

    if(path.size() == n){
        if(ts[path.back()][u] != 0 && ts[path.back()][u] != 10000){
            if(sw + ts[path.back()][u] < min_w){
                int prev = path.back(); // *
                path.push_back(u);
                min_w = sw + ts[prev][u];
                ans = path;
                path.pop_back();
            }
        }

        return;
    }

    for(int i=1; i<=n; i++){
        if(!vis[i] && ts[path.back()][i] != 0 && ts[path.back()][i] != 10000){
            int prev = path.back(); // *
            vis[i] = true;
            path.push_back(i);
            sw += ts[prev][i];

            Hamilton();

            sw -= ts[prev][i];
            path.pop_back();
            vis[i] = false;
        }
    }

}

void solve(){
    cin >> n >> u;
    min_w = 1e9;
    sw = 0;
    ts.assign(n+1,vector<int>(n+1,0));
    vis.assign(n+1,false);
    ans.clear();
    path.clear();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> ts[i][j];
        }
    }

    path.push_back(u);
    vis[u] = true;
    Hamilton();

    if(ans.size() == 0)
        cout << 0 << endl;
    else{
        cout << min_w << endl;
        for(int x : ans)
            cout << x << " ";

        cout << endl;
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