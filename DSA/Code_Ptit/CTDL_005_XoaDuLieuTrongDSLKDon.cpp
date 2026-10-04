#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6;
ll n, m;
ll a[MAXN], b[MAXN];

/* Ý tưởng:

*/

void solve() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    int k;
    cin >> k;

    for(int i=0; i<n; i++){
        if(a[i] != k)
            cout << a[i] << ' ';
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