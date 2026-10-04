#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng:

*/

void solve() {
    int n;
    cin >> n;

    int a[n], b[n];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    sort(a,a+n);
    sort(b,b+n,greater<int>());

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += a[i] * b[i];
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
              
    while(t--){
       solve(); 
    }
    return 0;
}