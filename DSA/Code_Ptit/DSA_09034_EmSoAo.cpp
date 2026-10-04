#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/
int n,m;
char a[1001][1001];
pair<int,int> dij[8] = {{0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}};

void dfs(int i, int j){
    a[i][j] = '.';
    for(int k=0; k<8; k++){
        int i1 = i + dij[k].first;
        int j1 = j + dij[k].second;

        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'W'){
            dfs(i1,j1);
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i=1; i <=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] == 'W'){
                ++cnt;
                dfs(i,j);
            }
        }
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
              
    while(t--){
       solve(); 
    }
    return 0;
}