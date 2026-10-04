#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN];

/* Ý tưởng:

*/


ll C[1005][1005];

void sinh(){
    C[0][0] = 1;
    for(int i=1; i<=1000; i++){
        for(int j=0; j<=i; j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            C[i][j] %= mod;
        }
    }
}

void solve(){
    sinh();
    int i,j;
    cin >> i >> j;

    cout << C[i][j] << endl;

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