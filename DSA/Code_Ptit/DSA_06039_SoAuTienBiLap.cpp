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


void solve() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    map<ll,ll> mp;
    ll val = -1;

    for(int i=0; i<n; i++){
        mp[a[i]]++;
    }


    for(int i=0; i<n; i++){
        if(mp[a[i]] > 1){
            val = a[i];
            break;
        }
    }
    
    if(val == -1)
        cout << "NO" << endl;
    else
        cout << val << endl;
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