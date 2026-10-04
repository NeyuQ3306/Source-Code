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
        cin >> n;
        a.assign(n+1, vector<int>(n+1));

        for(int i=1; i<=n; i++){
            int cnt = 0;
            for(int j=1; j<=n; j++){
                cin >> a[i][j];
                if(a[i][j] != 0 && a[i][j] != 10000) ++cnt;
            }
            cout << cnt << " ";
        }

        cout << endl;
    }

    else{
        cin >> n;
        a.assign(n+1, vector<int>(n+1));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> a[i][j];

                if(a[i][j] != 0 && a[i][j] != 10000 && i < j){
                    canh.push_back({i, {j, a[i][j]}});
                }
            }
        }

        cout << n << " " << canh.size() << endl;
        for(auto x : canh)
            cout << x.first << " " << x.second.first << " " << x.second.second << endl;
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