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
        int n,k;
        cin >> n >> k;

        ll a[n];
        for(ll &x : a)
            cin >> x;

        if(n-k >= k){
            sort(a,a+n);
            ll num1 = 0, num2 = 0;
            for(int i=0; i<k; i++)
                num1 += a[i];

            for(int i=k; i<n; i++)
                num2 += a[i];

            cout << abs(num2-num1) << endl;
        }

        else{
            sort(a,a+n,greater<ll>());
            ll num1 = 0, num2 = 0;
            for(int i=0; i<k; i++)
                num1 += a[i];

            for(int i=k; i<n; i++)
                num2 += a[i];

            cout << abs(num2-num1) << endl;
        }
    }

    return 0;
}
