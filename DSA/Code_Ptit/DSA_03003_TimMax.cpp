#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

/* Ý tưởng:

*/



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
        int n;
        cin >> n;

        int a[n];
        for(int &x : a)
            cin >> x;

        sort(a,a+n);
        ll sum = 0;
        for(int i=0; i<n; i++){
            sum += (a[i] * i) % mod;
            sum %= mod;
        }

        cout << sum << endl;
    }


    return 0;
}
