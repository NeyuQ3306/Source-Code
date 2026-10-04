#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Số thao tác tối thiểu để biến xâu s thành xâu t cho trước - Edit Distance
- Cho 3 thao tác insert, delete và replace hãy tìm số thao tác tối thiểu:
- dp[i][j] = số phép biến đổi ít nhất để biến S[1..i] thành T[1..j]
dp[i][j] = 1 + min(
    dp[i-1][j],      // delete
    dp[i][j-1],      // insert
    dp[i-1][j-1]     // replace
)
- Nếu ko cho phép replace thì: ans = Edit distance = n + m - 2 * LCS
*/

int dp[105][105];

void solve() {
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1 = "2" + s1;
    s2 = "3" + s2;

    for(int i=1; i<=n; i++) dp[i][0] = i;
    for(int i=1; i<=m; i++) dp[0][i] = i;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
           if(s1[i] != s2[j])  dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
           else  dp[i][j] = dp[i-1][j-1];

        //    cout << i << " " << j << " " <<  dp[i][j] << endl;
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