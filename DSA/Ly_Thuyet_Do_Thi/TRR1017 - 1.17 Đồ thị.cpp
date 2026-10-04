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
        cin >> n >> m;
        ideg.assign(n+1,0);
        odeg.assign(n+1,0);

        for(int i=0; i<m; i++){
            int x,y;
            cin >> x >> y;

            odeg[x]++;
            ideg[y]++;
        }

        for(int i=1; i<=n; i++){
            cout << ideg[i] << " " << odeg[i] << endl;
        }
    }

    else{
        cin >> n >> m;
        edge.clear();

        for(int i=0; i<m; i++){
            int x,y;
            cin >> x >> y;

            edge.insert({x,y});
        }

        lt.assign(n+1, vector<int>(edge.size() + 1));
        for(int i=1; i<=n; i++){
            int cnt = 1;
            for(auto x : edge){
                if(i == x.first)
                    lt[i][cnt] = 1;
                else if(i == x.second)
                    lt[i][cnt] = -1;

                ++cnt;
            }
        }

        cout << n << " " << m << endl;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=edge.size(); j++)
                cout << lt[i][j] << " ";

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