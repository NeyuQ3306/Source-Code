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
    for(int i=0; i<n; i++)
        cin >> a[i];

    ll cur_s = a[0];
    ll ans = a[0];

    for(int i=1; i<n; i++){
        /* thuật toán ở đây là ở mỗi vị trí i ta có 2 lựa chọn
1 là cộng tiếp a[i] vào mảng con hiện tại, 2 là bắt đầu mảng con mới
từ vị trí i nếu a[i] > cur_s + a[i] */
        cur_s = max(a[i], cur_s + a[i]);
        ans = max(ans, cur_s);
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