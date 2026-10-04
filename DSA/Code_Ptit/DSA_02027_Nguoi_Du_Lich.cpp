#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n, c[20][20], x[20];
int ans = 1e9, dis = 0, minc = 1e9;
bool vis[20];

void ql(int i, int dis){
    for(int j=2; j<=n; j++){
        if(!vis[j]){
            x[i] = j;
            vis[j] = true;
            dis += c[x[i-1]][x[i]];

            if(i == n) ans = min(ans, dis + c[x[i]][1]);
            else if((n-i+1) * minc + dis < ans) ql(i+1,dis);

            dis -= c[x[i-1]][x[i]];
            vis[j] = false;
        }
    }
}

void solve() {
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> c[i][j];
            if(c[i][j] != 0) minc = min(minc, c[i][j]);
        }
    } 
    
    // cout << minc << endl;
    x[1] = 1;
    ql(2,0);
    cout << ans << endl;
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