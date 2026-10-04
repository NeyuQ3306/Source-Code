#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

/* Ý tưởng: 
*/

struct matran{
    ll a[2][2] = {1,1,1,0};

    friend matran operator * (const matran &x, const matran &y){
        matran res;

        memset(res.a,0,sizeof(res.a));

        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                for(int k=0; k<2; k++){
                    res.a[i][j] += (x.a[i][k] % mod * y.a[k][j] % mod);
                    res.a[i][j] %= mod;
                }
            }
        }

        return res;
    }
};

matran Donvi(){
    matran res;
    memset(res.a,0,sizeof(res.a));
    res.a[0][0] = res.a[1][1] = 1;

    return res;
}

matran binpow(matran x, ll n){
    if(n==0)
        return Donvi();
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
        ll n;
        cin >> n;

        matran x;


        matran res = binpow(x,n-1);
        cout << res.a[0][0] << endl;
        
    }

    return 0;
}
