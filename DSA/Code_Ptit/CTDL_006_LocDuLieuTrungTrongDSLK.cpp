#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6;
ll n, m;
ll a[MAXN], b[MAXN];

/* Ý tưởng:

*/

void solve() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    map<int,int> mp;
    for(int i=0; i<n; i++)
        mp[a[i]]++;

    for(int x : a){
        if(mp[x] != 0){
            cout << x << ' ';
            mp[x] = 0;
        }
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