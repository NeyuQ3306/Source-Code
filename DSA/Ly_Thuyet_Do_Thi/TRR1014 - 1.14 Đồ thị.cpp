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
vector<vector<int>> lt;
vector<pair<int,int>> edge;
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
        a.assign(n+1, vector<int>(n+1));
        edge.clear();

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int x;
                cin >> x;

                if(x){
                    edge.push_back({i,j});
                }
            }
        }

        cout << n << " " << edge.size() << endl;
        for(int i=1; i<=n; i++){
            for(int j=0; j<edge.size(); j++){
                if(i == edge[j].first) cout << 1 << " ";
                else if(i == edge[j].second) cout << -1 << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }

        cout << n << " " << edge.size() << endl;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=edge.size(); j++){
                cout << lt[i][j] << " ";
            }

            cout << endl;
        }
    }
}

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("CT.INP","r",stdin);
    // freopen("CT.OUT","w",stdout);
    // #else
    // freopen("DT.INP","r",stdin);
    // freopen("DT.OUT","w",stdout);
    // #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}