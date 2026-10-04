#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e3;
ll n, m, k;
ll a[MAXN];


/* Ý tưởng: 

*/


void solve() {
    int t;
    cin >> t;

    while(t--){
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> a[i];

        ll ans = LLONG_MAX;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(abs(a[i] + a[j]) < abs(ans - 0))
                    ans = a[i] + a[j];
            }
        }

        cout << ans;
        cout << endl;


    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}