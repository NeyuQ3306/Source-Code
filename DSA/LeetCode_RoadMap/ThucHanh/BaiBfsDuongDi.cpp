#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/
int n,m;
vector<vector<int>> a;
vector<vector<bool>> vis;

void bfs(){
    queue<pair<pair<int,int>, int>> q;
    q.push({{1,1}, 0});
    vis[1][1] = true;

    while(!q.empty()){
        auto t = q.front();
        q.pop();

        int i = t.fi.fi, j = t.fi.se, step = t.se;
        if(i == n && j == m){
            cout << step << endl;
            return;
        }

        if(i+1 <= n){
            int t1 = abs(a[i+1][j] - a[i][j]);
            if(t1 > 0 && i + t1 > 0 && i + t1 <= n && !vis[i+t1][j]){
                q.push({{i+t1,j}, step+1});
                vis[i+t1][j] = true;
            }
        }
        if(j+1 <= m){
            int t2 = abs(a[i][j] - a[i][j+1]);
            if(t2 > 0 && j + t2 > 0 && j + t2 <= m && !vis[i][j+t2]){
                q.push({{i,j+t2}, step + 1});
                vis[i][j+t2] = true;
            }
        }
        if(i+1 <= n && j+1 <= m){
            int t3 = abs(a[i][j] - a[i+1][j+1]);
            if(t3 > 0 && i+t3 > 0 && i+t3 <=n && j+t3>0 && j+t3 <= m && !vis[i+t3][j+t3]){
                q.push({{i+t3,j+t3}, step+1});
                vis[i+t3][j+t3] = true;
            }
        }
    }

    cout << -1 << endl;
}

void solve() {
    cin >> n >> m;
    a.assign(n+1,vector<int>(m+1));
    vis.assign(n+1,vector<bool>(m+1, false));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }

    bfs();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
              
    while(t--){
       solve(); 
    }
    return 0;
}