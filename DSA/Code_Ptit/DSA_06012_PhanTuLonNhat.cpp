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
        int k;
        cin >> n >> k;
        for(int i=0; i<n; i++)
            cin >> a[i];

        sort(a,a+n,greater<int>());
        for(int i=0; i<k; i++)
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