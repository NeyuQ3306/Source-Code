#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
int a[505][505];
int d[505][505];
int di[4] = {0,-1,0,1};
int dj[4] = {-1,0,1,0};

void Dijkstra(int i,int j){
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    d[i][j] = a[i][j];
    pq.push({a[i][j], {i,j}});

    while(!pq.empty()){
        pair<int,pair<int,int>> top = pq.top();
        pq.pop();

        int dis = top.first, u = top.second.first, v = top.second.second;
        if(dis > d[u][v]) continue;

        for(int k=0; k<4; k++){
            int i1 = u + di[k];
            int j1 = v + dj[k];

            if(i1>=1 && i1<=n && j1>=1 && j1<=m){
                if(d[i1][j1] > d[u][v] + a[i1][j1]){
                    d[i1][j1] = d[u][v] + a[i1][j1];
                    pq.push({d[i1][j1], {i1,j1}});
                }
            }
        }
    }

    cout << d[n][m] << endl;
}

void solve() {
    cin >> n >> m;
    memset(a,0,sizeof(a));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) d[i][j] = 1e9;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cin >> a[i][j];
    }

    Dijkstra(1,1);
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