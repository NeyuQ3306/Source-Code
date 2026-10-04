#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
ll n, m, k = 3;
ll a[MAXN], dp[MAXN];

/* Ý tưởng:

*/

void solve(){
    memset(dp,0,sizeof(dp));
    dp[0] = dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++){
        for(int j=k; j>0; j--){
            if(i-j >= 0)
                dp[i] += dp[i-j];
        }
    }

    cout << dp[n] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        cin >> n;
        solve();
    }
    
    return 0;
}