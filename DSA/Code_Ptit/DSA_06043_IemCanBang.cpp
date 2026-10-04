#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
ll n, m, cnt, k;
ll a[MAXN], b[MAXN], c[MAXN];
vector<string>res;
bool check_final = false;

/* Ý tưởng: 
*/


void solve() {
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    ll prefixsum[n+1];
    prefixsum[1] = a[1];
    for(int i=2; i<=n; i++)
        prefixsum[i] = prefixsum[i-1] + a[i];

    ll ans = -1;
    for(int i=2; i<=n; i++){
        if(prefixsum[i-1] == prefixsum[n] - prefixsum[i]){
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    
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
        solve();
    }

    return 0;
}