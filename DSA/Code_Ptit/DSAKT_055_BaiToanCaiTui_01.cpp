#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Tương tự như bài dãy con tổng bằng s ta sử dụng dp 2 chiều với i là số lượng
vật đã chọn và j là tổng khối lượng tối đa của túi
- Với mỗi đồ vật ta có 2 lựa chọn: LẤY hoặc KO LẤY
+ Lấy nếu tồn tại dp[i][s - w[i]] <=> s - w[i] >= 0
+ Ko lấy thì ta chọn dp[i-1][s]
*/

ll dp[1005][1005];

void solve() {
    int n,s;
    cin >> n >> s;

    int w[1005], c[1005];
    for(int i=1; i<=n; i++) cin >> w[i];
    for(int i=1; i<=n; i++) cin >> c[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            if(j - w[i] >= 0) dp[i][j] = max(dp[i-1][j-w[i]] + c[i], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][s] << endl;
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