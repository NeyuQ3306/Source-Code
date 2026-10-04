#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
ll n, m, cnt, k;
ll a[MAXN], b[MAXN];
vector<string>res;
bool check_final = false;

/* Ý tưởng:
*/

ll binpow(ll a, ll b, ll c){
    if(b==0)
        return 1;

    ll X = binpow(a,b/2,c);
    if(b%2==0)
        return (X%c * X%c) % c;
    else
        return (X%c * X%c * a%c) % c;
}

void solve() {
    cin >> n >> m;
    if(n==0 && m==0){
        check_final = true;
        return;
    }

    else
        cout << binpow(n%mod,m,mod) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    check_final = false;

    while(!check_final){
        solve();
    }

    return 0;
}