#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: dp[i][j]: cỡ hình vuông lớn nhất với góc dưới bên phải là ô (i,j)
- CT truy hồi: dp[i][j] = min{dp[i-1][j], dp[i][j-1], dp[i-1][j-1]} + 1;
- Bài toán con nhỏ nhất: dp[i][j] = a[i][j];

*/

int n,m;
int a[505][505], dp[505][505];

void solve() {
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
            dp[i][j] = a[i][j];
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(dp[i][j]){
                dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
            }

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
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