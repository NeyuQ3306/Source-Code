#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


/* Ý tưởng:

*/

const long long mod = 1e9 + 7;
int n,m,u;
vector<vector<int>> adj;
vector<set<int>> adjs;
vector<bool> vis;
vector<int> deg;
vector<int> path;
vector<vector<int>> a;
vector<pair<int,int>> edge;
vector<pair<int,pair<int,int>>> canh;
vector<vector<int>> CC;
vector<int> tmp;

void solve() {
    int x;
    cin >> x;

    if(x==1){
        cin >> n >> m;
        a.assign(n+1, vector<int>(n+1));
        deg.assign(n+1, 0);

        for(int i=0; i<m; i++){
            int x,y,z;
            cin >> x >> y >> z;

            deg[x]++;
            deg[y]++;
        }

        for(int i=1; i<=n; i++)
            cout << deg[i] << " ";
        cout << endl;
    }

    else{
        cin >> n >> m;
        a.assign(n+1, vector<int>(n+1));

        for(int i=0; i<m; i++){
            int x,y,z;
            cin >> x >> y >> z;

            a[x][y] = a[y][x] = z;
        }

        cout << n << endl;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j)
                    cout << 0 << " ";
                else if(a[i][j] != 0)
                    cout << a[i][j] << " ";
                else cout << 10000 << " ";
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