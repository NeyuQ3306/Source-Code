#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Dạng quy hoạch động trên string - Xâu con đối xứng dài nhất
- Ta sử dụng dp[l][r] = 1 nếu xâu con từ vị trí l->r là xâu đối xứng, ngược lại = 0
- Điều kiện đầu:
+ Độ dài xâu = 1: Luôn là xâu đối xứng
+ Độ dài xâu = 2: Là xâu đối xứng <=> s[l] = s[r]
- Công thức truy hồi: Xâu từ vị trí l->r là xâu đối xứng nếu thỏa mãn:
+ Điều kiện cần: s[l] = s[r]
+ Điều kiện đủ: dp[l+1][r-1] = 1
- Do công thức truy hồi phụ thuộc vào xâu con nằm trong xâu đang xét nên ta duyệt x
là chiều dài xâu đang xét, vì xét tăng dần nên khi xét xâu dài hơn ta đã có sẵn dp của
xâu con nằm trong

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int>> dp(n+5, vector<int>(n+5, 0));

    // ta xét từ vị trí 1 nên nối thêm 1 kí tự ở đầu 
    s = "@" + s;

    // duyệt theo chiều dài xâu con đối xứng dài nhất có thể nhận
    for(int x=1; x<=n; x++){
        // chọn mốc left, ta có chiều dài đoạn l->r là: r-l+1 = x <=> r = l+x-1
        for(int l=1; l+x-1 <= n; l++){
            int r = l+x-1;

            if(x==1) dp[l][r] = 1;
            else if(x==2) dp[l][r] = (s[l] == s[r]);
            else if(s[l] == s[r]) dp[l][r] |= dp[l+1][r-1];
        }
    }

    int ans = 1;
    for(int l=1; l<=n; l++){
        for(int r=1; r<=n; r++){
            if(dp[l][r])  ans = max(ans, r-l+1);
        }
    }

    cout << ans << endl;
}


- Hoặc code như này cũng được cho dễ hiểu dp[i][j] = true nếu xâu con từ i->j là xâu đối
xứng: 
CT truy hồi sẽ là: dp[i][j] |= dp[i+1][j-1]
Bài toán cơ sở: dp[i][i] = 1, dp[i][j] = 1 nếu j - i = 1 (có 2 phần tử) và s[i] == s[j]
*/

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int>> dp(n+5, vector<int>(n+5, 0));

    int ans = 0;
    // dp[i][j] = 1 nếu đoạn từ i->j là xâu đối xứng
    for(int  i=n-1; i>=0; i--){
        for(int j=i; j<n; j++){
            if(i==j) dp[i][j] = 1;
            else if(s[i] == s[j]){
                if(j - i == 1) dp[i][j] = 1;
                else dp[i][j] |= dp[i+1][j-1];
            }


            if(dp[i][j]) ans = max(ans, j-i+1);
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