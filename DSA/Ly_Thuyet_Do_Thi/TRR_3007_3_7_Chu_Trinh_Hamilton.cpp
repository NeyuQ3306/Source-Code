#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;


/* Ý tưởng:

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
vector<vector<int>> res;
int cnt = 0;

void Hamilton(int i){
    for(auto x : adjs[path[i-1]]){
        if(!vis[x]){
            vis[x] = true;
            path[i] = x;

            if(i == n){
                if(adjs[path[i]].count(u)){
                    ++cnt;
                    for(int i=1; i<=n; i++)
                        cout << path[i] << " ";

                    cout << u << endl;
                }
            }

            else Hamilton(i+1);

            vis[x] = false;
        }
    }
}

void solve(){
    cin >> n >> u;
    cnt = 0;
    ke.assign(n+1,vector<int>(n+1,0));
    adjs.assign(n+1,set<int>());
    vis.assign(n+1,false);
    path.assign(n+5,0);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> ke[i][j];

            if(ke[i][j])
                adjs[i].insert(j);
        }
    }

    path[1] = u;
    vis[u] = true;
    Hamilton(2);

    cout << cnt << endl;
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