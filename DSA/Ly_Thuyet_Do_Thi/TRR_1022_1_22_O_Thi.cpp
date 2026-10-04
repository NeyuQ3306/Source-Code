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
        cin >> n >> m;
        ideg.assign(n+1,0);
        odeg.assign(n+1,0);

        for(int i=0; i<m; i++){
            int x,y,z;
            cin >> x >> y >> z;

            ideg[x]++;
            odeg[y]++;
        }

        for(int i=1; i<=n; i++)
            cout << odeg[i] << " " << ideg[i] << endl;
    }

    else{
        cin >> n >> m;
        ts.assign(n+1, vector<int>(n+1, 10000));

        for(int k=0; k<m; k++){
            int i,j,w;
            cin >> i >> j >> w;

            ts[i][j] = w;
        }

        cout << n << endl;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j) cout << 0 << " ";
                else cout << ts[i][j] << " ";
            }

            cout << endl;
        }
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