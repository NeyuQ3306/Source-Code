#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng:

*/

void solve() {
    int n,k;
    cin >> n >> k;

    ll dp[n+1] = {0};
    dp[0] = dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++){
        for(int j=k; j>=1; j--){
            if(i-j >= 0){
                dp[i] += dp[i-j];
                dp[i] %= mod;
            }
        }
    }

    cout << dp[n] << endl;
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