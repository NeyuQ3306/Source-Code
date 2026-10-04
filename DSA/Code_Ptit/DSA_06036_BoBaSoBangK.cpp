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

    loop:
    while(t--){
        ll n,k;
        cin >> n >> k;

        ll a[n];
        for(ll &x : a)
            cin >> x;

        sort(a,a+n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ll target = k - a[i] - a[j];
                if(binary_search(a+j+1,a+n,target)){
                    cout << "YES" << endl;
                    goto loop;
                }

            }
        }

        cout << "NO" << endl;
        
    }

    return 0;
}
