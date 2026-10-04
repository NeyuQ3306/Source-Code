#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
ll n, m, cnt, k;
ll a[MAXN], b[MAXN];
vector<string>res;
bool check_final = false;

/* Ý tưởng:
*/




void solve() {
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> a[i];

    auto it = lower_bound(a,a+n,k);
    if(*it != k)
        cout << "NO\n";
    else
        cout << it - a + 1 << endl;
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