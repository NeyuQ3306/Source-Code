#include <bits/stdc++.h>
using namespace std;
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
set<pair<int,int>> edge;
vector<pair<int,pair<int,int>>> canh;
vector<vector<int>> CC;
vector<int> tmp;

void solve() {
    int x;
    cin >> x;

    if(x==1){
        cin >> n;
        ideg.assign(n+1,0);
        odeg.assign(n+1,0);

        for(int i=1; i<=n; i++){
            int cnt;
            cin >> cnt;

            ideg[i] = cnt;
            for(int j=1; j<=cnt; j++){
                int x;
                cin >> x;

                odeg[x]++;
            }
        }

        for(int i=1; i<=n; i++)
            cout << odeg[i] << " " << ideg[i] << endl;
    }

    else{
        cin >> n;
        edge.clear();

        for(int i=1; i<=n; i++){
            int k;
            cin >> k;

            for(int j=1; j<=k; j++){
                int x;
                cin >> x;

                edge.insert({i,x});
            }
        }

        cout << n << " " << edge.size() << endl;
        for(auto x : edge)
            cout << x.first << " " << x.second << endl;
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