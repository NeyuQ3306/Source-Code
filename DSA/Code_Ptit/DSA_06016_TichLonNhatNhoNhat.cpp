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
        ll n,m;
        cin >> n >> m;

        ll a[n], b[m];
        for(ll &x : a)
            cin >> x;
        for(ll &y : b)
            cin >> y;

        sort(a,a+n);
        sort(b,b+m);

        cout << a[n-1] * b[0] << endl;
        
    }

    return 0;
}
