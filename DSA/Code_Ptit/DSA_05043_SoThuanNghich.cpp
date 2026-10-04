#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int dp[1005][1005];

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;
    memset(dp,0,sizeof(dp));

    // dp[i][j] = 1 neu xau con tu i - > j la xau doi xung
    for(int i=n-1; i>=0; i--){
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