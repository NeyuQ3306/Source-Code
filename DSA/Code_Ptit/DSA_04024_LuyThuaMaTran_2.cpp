#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

/* Ý tưởng:
   Lũy thừa ma trận + lấy mod trong quá trình nhân
*/

struct matran{
    int row, col;
    ll a[100][100];

    // Nạp chồng toán tử * cho phép nhân ma trận
    friend matran operator * (const matran &x, const matran &y){
        matran res;
        res.row = x.row;
        res.col = y.col;

        memset(res.a, 0, sizeof(res.a));
        for(int i = 0; i < x.row; i++){
            for(int j = 0; j < y.col; j++){
                for(int k = 0; k < x.col; k++){
                    res.a[i][j] =
                        (res.a[i][j] + x.a[i][k] * y.a[k][j]) % mod;
                }
            }
        }
        return res;
    }
};

matran matrandonvi(int n){
    matran res;
    res.row = res.col = n;
    memset(res.a, 0, sizeof(res.a));
    for(int i = 0; i < n; i++)
        res.a[i][i] = 1;
    return res;
}

matran binpow(matran x, ll k){
    if(k == 0) return matrandonvi(x.row);
    if(k == 1) return x;

    matran half = binpow(x, k / 2);
    if(k % 2 == 0)
        return half * half;
    else
        return x * (half * half);
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    matran x;
    x.row = x.col = n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> x.a[i][j];

    matran res = binpow(x, k);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + res.a[i][n-1]) % mod;
    }

    cout << ans << '\n';
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
