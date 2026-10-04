#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e7;



/* Ý tưởng: 

*/


void solve() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        for(ll &x : a) cin >> x;

        set<int> se;
        for(ll x : a){
            if(x == 0) se.insert(0);
            while(x){
                se.insert(x % 10);
                x /= 10;
            }
        }

        for(int d : se) cout << d << ' ';
        cout << '\n';
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