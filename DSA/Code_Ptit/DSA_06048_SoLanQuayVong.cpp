#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e7;
ll n, m, cnt, k;
// ll a[MAXN], b[MAXN];

/* Ý tưởng: 
*/



void solve() {
    cin >> n;
    ll a[n], b[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    // trạng thái cần tìm
    copy(a,a+n,b);

    int cnt = 0;
    sort(a,a+n);

    if(equal(a,a+n,b)){
        cout << cnt << endl;
        return;
    }

    while(!equal(a,a+n,b)){
        ++cnt;
        ll last = a[n-1];
        for(int i=n-2; i>=0; i--)
            a[i+1] = a[i];

        a[0] = last;
    }

    cout << cnt << endl;

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