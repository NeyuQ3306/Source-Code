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
        ll n;
        cin >> n;

        ll a[n];
        for(ll &x : a)
            cin >> x;

        ll ans = 0;
        sort(a,a+n);
        map<ll,int> mp;

        for(ll x : a)
            mp[x] = 1;

        for(ll i = *min_element(a,a+n); i<= *max_element(a,a+n); i++){
            if(mp.count(i) == 0)
                ++ans;
        }
        
        cout << ans << endl;
    }

    return 0;
}
