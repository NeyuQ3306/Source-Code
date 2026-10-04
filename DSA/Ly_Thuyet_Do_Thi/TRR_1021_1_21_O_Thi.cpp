#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;


/* Ý tưởng:

*/

const long long mod = 1e9 + 7;
int n,m,u;
vector<set<int>> adj;
vector<set<int>> adjs;
vector<bool> vis;
vector<int> ideg;
vector<int> odeg;
vector<int> path;
vector<vector<int>> ke;
vector<vector<int>> lt;
vector<vector<int>> ts;
set<pair<int,int>> edge;
vector<pair<int,pair<int,int>>> canh;
vector<vector<int>> CC;
vector<int> tmp;

void solve() {
    int x;
    cin >> x;

    if(x==1){
        cin >> n;
        ts.assign(n+1,vector<int>(n+1));
        ideg.assign(n+1,0);
        odeg.assign(n+1,0);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> ts[i][j];

                if(ts[i][j] != 0 && ts[i][j] != 10000){
                    ideg[i]++;
                    odeg[j]++;
                }
            }
        }
        for(int i=1; i<=n; i++)
            cout << odeg[i] << " " << ideg[i] << endl;
    }

    else{
        cin >> n;
        ts.assign(n+1,vector<int>(n+1));
        canh.clear();

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> ts[i][j];

                if(ts[i][j] != 0 && ts[i][j] != 10000){
                    canh.push_back({i,{j,ts[i][j]}});
                }
            }
        }
        cout << n << " " << canh.size() << endl;
        for(auto x : canh)
            cout << x.fi << " " << x.se.fi << " " << x.se.se << endl;
    }

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);
    #else
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}