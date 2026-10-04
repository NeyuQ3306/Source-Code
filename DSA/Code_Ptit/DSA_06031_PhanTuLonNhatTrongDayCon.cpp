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
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> a[i];

    multiset<int>se;
    for(int i=0; i<k; i++)
        se.insert(a[i]);

    cout << *se.rbegin() << " ";
    for(int i=k; i<n; i++){
        se.insert(a[i]);
        se.erase(se.find(a[i-k]));

        cout << *se.rbegin() << " ";
    }
    cout << endl;
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