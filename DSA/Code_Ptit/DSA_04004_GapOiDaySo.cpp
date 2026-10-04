#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng:

*/

int gapdoi(ll n, ll k){
    ll mid = pow(2,n-1);
    if(mid == k)
        return n;

    if(k < mid)
        return gapdoi(n-1,k);
    
    return gapdoi(n-1, k-mid);
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
        ll x,y;
        cin >> x >> y;

        cout << gapdoi(x,y) << endl;
    }
    return 0;
}