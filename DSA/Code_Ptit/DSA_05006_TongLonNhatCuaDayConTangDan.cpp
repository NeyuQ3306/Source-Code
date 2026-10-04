#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


/* Ý tưởng:

*/

const long long mod = 1e9 + 7;
ll n,m,k;
ll a[100005];
ll dp[100005];

void solve() {
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];

	memset(dp,0,sizeof(dp));
	ll ans = a[0];
	dp[0] = a[0];
	for(int i=1; i<n; i++){
		dp[i] = a[i];
		for(int j=0; j<i; j++){
			if(a[i] > a[j]){
				dp[i] = max(dp[i], dp[j] + a[i]);
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

    // int t = 1;

    while(t--){
    	solve();
    }
    return 0;
}