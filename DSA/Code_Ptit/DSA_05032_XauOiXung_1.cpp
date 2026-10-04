#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

ll dp[1001][1001];

void solve() {
    string s;
    cin >> s;

    string rs = s;
    reverse(rs.begin(), rs.end());

    ll n = s.size();
    s = "2" + s;
    rs = "1" + rs;

    // dp[i][j]: do dai xau con chung dai nhat tu i toi j
    ll max_l = 0;
    for(int i=1; i<s.size(); i++){
        for(int j=1; j<rs.size(); j++){
            if(s[i] == rs[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            max_l = max(max_l, dp[i][j]);
        }
    }

    cout << n - max_l << endl;
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