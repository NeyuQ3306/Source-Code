#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6;
ll n, m, k;
ll a[MAXN];


/* Ý tưởng: 

*/



void solve() {
    int t;
    cin >> t;

    while(t--){
        cin >> n;

        for(int i=0; i<n; i++)
            cin >> a[i];

        int min_v1 = INT_MAX, min_v2 = INT_MAX;
        for(int i=0; i<n; i++){
            if(a[i] < min_v1){
                min_v2 = min_v1;
                min_v1 = a[i];
            }

            else if(min_v1 < a[i] && min_v2 > a[i])
                min_v2 = a[i];
        } 
        
        if(min_v2 == INT_MAX)
            cout << "-1" << endl;
        else
            cout << min_v1 << ' ' << min_v2 << endl;
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