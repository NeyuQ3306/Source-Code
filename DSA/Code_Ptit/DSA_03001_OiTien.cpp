#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e5;
ll n, m, cnt, k;
ll a[MAXN], b[MAXN];

/* Ý tưởng: 
*/



void solve() {
    cin >> n;
    ll ans = 0;

    int menhgia[10] = {1000,500,200,100,50,20,10,5,2,1};
    for(int i=0; i<10; i++){
        ans += n/menhgia[i];
        n %= menhgia[i];
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