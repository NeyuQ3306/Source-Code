#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>

/* Ý tưởng:
- Cách trâu: duyệt mọi tập con, kiểm tra có K liên tiếp không => O(2^N) không khả thi

- DP: dp[i][j] = tổng lớn nhất xét đến vị trí i, j là số phần tử liên tiếp cuối cùng được chọn
    j = 0: không chọn A[i]
    j = 1..K-1: chọn A[i], đang có j phần tử liên tiếp

  Chuyển trạng thái:
    dp[i][0] = max(dp[i-1][0..K-1])   // không chọn i, reset đếm liên tiếp
    dp[i][j] = dp[i-1][j-1] + A[i]    // chọn i, liên tiếp thêm 1

  Kết quả: max(dp[N][0..K-1])
  ĐPT: O(N*K)
*/

int n, k;

void solve() {
    cin >> n >> k;
    vi a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    // dp[i][j]: tổng max tại vị trí i, j phần tử liên tiếp cuối được chọn
    vector<vll> dp(n+1, vll(k, 0));
    // dp[1][0] = 0 (không chọn A[1])
    // dp[1][1] = A[1] (chọn A[1], 1 liên tiếp)
    dp[1][0] = 0;
    if(k > 1) dp[1][1] = a[1];

    for(int i = 2; i <= n; i++){
        // Không chọn A[i]: lấy max của tất cả trạng thái trước
        dp[i][0] = *max_element(dp[i-1].begin(), dp[i-1].end());

        // Chọn A[i] với j phần tử liên tiếp
        for(int j = 1; j < k; j++){
            dp[i][j] = dp[i-1][j-1] + a[i];
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end()) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}