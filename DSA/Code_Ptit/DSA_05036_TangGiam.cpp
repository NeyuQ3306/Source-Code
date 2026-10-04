#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/


void solve() {
    int n;
    cin >> n;

    double a[n+10], b[n+10];
    for(int i=0; i<n; i++){
        double x,y;
        cin >> x >> y;

        a[i] = x, b[i] = y;
    }

    int dp[n+10];
    int ans = 1;
    dp[0] = 1;

    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(a[i] > a[j] && b[i] < b[j]){
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
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