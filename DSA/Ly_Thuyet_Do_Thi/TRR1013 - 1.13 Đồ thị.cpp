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
vector<vector<int>> a;
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
            for(int j=1; j<=n; j++){
                int x;
                cin >> x;

                if(x){
                    ++odeg[i];
                    ++ideg[j];
                }
            }
        }

        for(int i=1; i<=n; i++){
            cout << ideg[i] << " " << odeg[i] << endl;
        }
    }

    else{
        cin >> n;
        adj.assign(n+1, {});

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int x; cin >> x;
                if(x){
                    adj[i].insert(j);
                }
            }
        }

        cout << n << endl;
        for(int i=1; i<adj.size(); i++){
            cout << adj[i].size() << " ";
            for(int x : adj[i])
                cout << x << " ";

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