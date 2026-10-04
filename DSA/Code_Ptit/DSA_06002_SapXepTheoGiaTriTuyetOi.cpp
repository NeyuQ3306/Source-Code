#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6;
ll n, m, k;
ll a[MAXN], b[MAXN];

/* Ý tưởng:

*/

bool cmp(int a, int b){
    return abs(a-k) < abs(b-k);
}

void solve() {
    int t;
    cin >> t;

    while(t--){
        cin >> n >> k;

        for(int i=0; i<n; i++)
            cin >> a[i];

        stable_sort(a,a+n,cmp);
        for(int i=0; i<n; i++)
            cout << a[i] << ' ';


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