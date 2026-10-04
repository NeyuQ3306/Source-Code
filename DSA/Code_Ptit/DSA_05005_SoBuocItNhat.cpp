#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n;
int dp[1005];

void solve() {
    cin >> n;
    int a[n];
    for(int &x : a) cin >> x;

    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(a[i] >= a[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << n - *max_element(dp,dp+n) << endl;
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