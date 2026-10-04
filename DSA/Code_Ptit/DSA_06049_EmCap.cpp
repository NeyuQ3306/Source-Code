#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

/* Ý tưởng: 
*/



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
        ll n,k;
        cin >> n >> k;

        int a[n];
        for(int &x : a)
            cin >> x;

        ll ans = 0;
        sort(a,a+n);
        // tìm a[j] cuối cùng sao cho a[j] - a[i] < k <=> a[j] < k + a[i] => tìm >= k + a[i]

        for(int i=0; i<n; i++){
            auto it = lower_bound(a+i+1, a+n, k+a[i]);
            ans += it - a - 1 - i;
        }

        cout << ans << endl;
        
    }

    return 0;
}
