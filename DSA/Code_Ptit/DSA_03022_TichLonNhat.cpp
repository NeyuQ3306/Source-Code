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

    int a[n];
    for(int &x : a) cin >> x;

    sort(a,a+n);

    cout << max({a[0]*a[1], a[0]*a[1]*a[2], a[n-1]*a[n-2], a[n-1]*a[n-2]*a[n-3],a[n-1]*a[0]*a[1]}) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
              
    while(t--){
       solve(); 
    }
    return 0;
}