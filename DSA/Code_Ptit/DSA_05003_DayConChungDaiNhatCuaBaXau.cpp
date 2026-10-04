#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

ll dp[105][105][105];
void solve() {
    int x,y,z;
    string s,t,u;

    cin >> x >> y >> z >> s >> t >> u;
    s = "2" + s;
    t = "3" + t;
    u = "4" + u;

    // dp[i][j][w]: độ dài xâu con chung dài nhất từ 1->i của s, 1->j của t và 1->w của u
    ll ans = 0;
    for(int i=1; i<s.size(); i++){
        for(int j=1; j<t.size(); j++){
            for(int w=1; w<u.size(); w++){
                if(s[i] == t[j] && t[j] == u[w]) dp[i][j][w] = dp[i-1][j-1][w-1] + 1;
                // else if(s[i] == t[j]) dp[i][j][w] = max(dp[i-1][j][w], dp[i][j-1][w]);
                // else if(t[j] == u[w]) dp[i][j][w] = max(dp[i][j-1][w], dp[i][j][w-1]);
                else dp[i][j][w] = max(dp[i-1][j][w], max(dp[i][j-1][w], dp[i][j][w-1]));

                ans = max(ans, dp[i][j][w]);
            }
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