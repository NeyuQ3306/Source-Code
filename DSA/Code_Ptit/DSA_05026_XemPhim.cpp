#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Biến thể của bài toán cái túi 0-1
- Ta sử dụng dp[i][j] là trọng lượng tối đa của i con bò với giới hạn là j
- Với mỗi con bò ta có thể chọn hoặc ko chọn, nếu giới hạn còn lại cho phép ta lấy
thêm <=> s - w[i] >= 0
*/

ll dp[105][25005];

void solve() {
    int s,n;
    cin >> s >> n;

    int w[n+1];
    for(int i=1; i<=n; i++) cin >> w[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            dp[i][j] = dp[i-1][j];
            if(j - w[i] >= 0) dp[i][j] = max(dp[i-1][j-w[i]] + w[i], dp[i-1][j]);
        }
    }

    cout << dp[n][s] << endl;
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