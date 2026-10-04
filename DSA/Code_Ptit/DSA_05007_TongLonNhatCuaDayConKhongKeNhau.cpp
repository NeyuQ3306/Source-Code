#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    int n;
    cin >> n;
    int a[n+100], dp[n+100];
    
    for(int i=0; i<n; i++) cin >> a[i];
    dp[0] = a[0];
    dp[1] = max(a[1], a[0]);

    // dp[i]: tai san lon nhat tinh den nha thu i
    for(int i=2; i<n; i++){
        dp[i] = max(dp[i-2] + a[i], dp[i-1]);
    }

    cout << *max_element(dp,dp+n) << endl;
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