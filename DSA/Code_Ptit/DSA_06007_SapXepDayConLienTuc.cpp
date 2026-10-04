#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6;
ll n, m, k;
ll a[MAXN], b[MAXN];

/* Ý tưởng: 
*/



void solve() {
    int t;
    cin >> t;

    while(t--){
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> a[i];

        copy(a,a+n,b);
        sort(b,b+n);

        int l=0, r=0;
        for(int i=0; i<n; i++){
            if(a[i] != b[i]){
                l = i + 1;
                break;
            }
        }

        for(int i=l; i<n; i++){
            if(a[i] != b[i]){
                r = i+1;
            }
        }

        cout << l << ' ' << r << endl;

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