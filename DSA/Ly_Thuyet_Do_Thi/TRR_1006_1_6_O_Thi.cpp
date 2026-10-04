#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


/* Ý tưởng:

*/

const long long mod = 1e9 + 7;
int t,n,m,u;
vector<vector<int>> adj;
vector<set<int>> adjs;
vector<bool> vis;
vector<int> deg;
vector<int> path;
vector<vector<int>> a;
vector<pair<int,int>> edge;
vector<vector<int>> CC;
vector<int> tmp;

void solve() {
    cin >> t;
    if(t==1){
        cin >> n >> m;
        a.assign(n+1, vector<int>(n+1));
        adj.clear();
        adj.resize(n + 1);
        edge.clear();

        for(int i=0; i<m; i++){
            int x,y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
            edge.push_back({x,y});
        }

        for(int i=1; i<=n; i++){
            cout << adj[i].size() << " ";
        }
    }


    else if(t==2){
        cin >> n >> m;
        a.assign(n+1, vector<int>(n+1));
        adj.clear();
        adj.resize(n + 1);
        edge.clear();

         for(int i=0; i<m; i++){
            int x,y;
            cin >> x >> y;
            edge.push_back({x,y});
        }

        sort(edge.begin(), edge.end());
        // for(auto e : edge){
        //     cout << e.first << " " << e.second << endl;
        // }

        m = edge.size();
        vector<vector<int>> B(n + 1, vector<int>(m, 0));
        for(int j = 0; j < m; j++){
            int u = edge[j].first;
            int v = edge[j].second;

            B[u][j] = 1;
            B[v][j] = 1;
        }

        cout << n << " " << m << endl;
        for(int i=1; i<=n; i++){
            for(int j=0; j<m; j++)
                cout << B[i][j] << " ";

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