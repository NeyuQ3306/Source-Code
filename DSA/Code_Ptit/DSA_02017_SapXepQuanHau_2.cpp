#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 105;
ll n, m, cnt, k;
ll a[MAXN][MAXN], b[MAXN], c[MAXN], X[MAXN];
ll cot[105], d1[105], d2[105];
ll ans = 0;

/* Ý tưởng: 
*/

void Try(int i){
    for(int j=1; j<=n; j++){
        if(cot[j] == 0 && d1[i+j-1] == 0 && d2[i-j+n] == 0){
            X[i] = j;
            cot[j] = d1[i+j-1] = d2[i-j+n] = 1;

            if(i==n){
                ll sum = 0;
                for(int k=1; k<=n; k++)
                    sum += a[k][X[k]];

                ans = max(ans,sum);
            }

            else
                Try(i+1);

            cot[j] = d1[i+j-1] = d2[i-j+n] = 0;
        }
    }
}

void solve() {
    ans = 0;
    memset(cot,0,sizeof(cot));
    memset(d1,0,sizeof(d1));
    memset(d2,0,sizeof(d2));
    
    n = 8;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> a[i][j];

    Try(1);
    cout << ans << endl;
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