#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

/* Ý tưởng: Tính số Fibo thứ N chia dư cho mod
*/

struct matran{
    ll row,col;
    ll a[100][100];

    friend matran operator * (const matran &x, const matran &y){
        matran res;
        res.row = x.row;
        res.col = y.col;

        memset(res.a,0,sizeof(res.a));

        for(int i=0; i<x.row; i++){
            for(int j=0; j<y.col; j++){
                for(int k=0; k<x.col; k++){
                    res.a[i][j] += (x.a[i][k] % mod * y.a[k][j] % mod);
                    res.a[i][j] %= mod;
                }
            }
        }

        return res;
    }
};

matran Donvi(int row){
    matran res;
    res.row = res.col = row;

    memset(res.a,0,sizeof(res.a));

    for(int i=0; i<res.row; i++)
        res.a[i][i] = 1;
    
    return res;
}

matran binpow(matran x, ll n){
    if(n==0)
        return Donvi(x.row);
    if(n==1)
        return x;

    else{
        matran X = binpow(x, n/2);
        if(n%2==0)
            return (X*X);
        else
            return (X*X*x);
    }
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
        ll n,k;
        cin >> n >> k;

        matran x;
        x.row = x.col = n;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin >> x.a[i][j];

        matran res = binpow(x,k);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout << res.a[i][j] << " ";

            cout << endl;
        }
        
    }

    return 0;
}
