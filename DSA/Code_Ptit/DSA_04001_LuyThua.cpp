#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m, cnt, k;
ll aa[MAXN][MAXN], a[MAXN];
vector<string>res;
bool check_final = false;

/* Ý tưởng: 
*/

ll binpow(ll a, ll b, ll c){
    if(b==0)
        return 1;
    else{
        ll X = binpow(a,b/2,c);

        if(b%2==0)
            return (X%c * X%c) % c;
        else
            return (X%c * X%c * a%c) % c;
    }
}



void solve() {
    cin >> n >> k;
    cout << binpow(n%mod,k,mod) << endl;

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