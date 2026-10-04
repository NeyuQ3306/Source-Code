#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
ll a[1001][1001], dp[1001][1001];

void solve() {
    cin >> n >> m;
    memset(dp,0,sizeof(dp));
    memset(a,0,sizeof(a));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cin >> a[i][j];
    }

    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1 && j==1) dp[i][j] = a[i][j];
            else if(i == 1) dp[i][j] = dp[i][j-1] + a[i][j];
            else if(j == 1) dp[i][j] = dp[i-1][j] + a[i][j];
            else dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + a[i][j];
        }
    }

    cout << dp[n][m] << endl;
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