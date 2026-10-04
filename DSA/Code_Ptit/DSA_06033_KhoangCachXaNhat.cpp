#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

/* Ý tưởng: Ta sử dụng 2 con trỏ trên 2 mảng Lmin, Rmax
- Lmin[i] = min[0...i], Rmax[j] = max[j...n-1]
- Mục tiêu là j-i max thì ta mong muốn i càng nhỏ càng tốt
- Ta xét Lmin[i] < Rmax[j] để chắc chắn trong đoạn i,j tồn tại 1 cặp a[i] < a[j]
*/

ll maxIndexDiff(ll a[], ll n){
    vector<ll> Lmin(n), Rmax(n);

    Lmin[0] = a[0];
    for(int i = 1; i < n; i++)
        Lmin[i] = min(Lmin[i-1], a[i]);

    Rmax[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--)
        Rmax[i] = max(Rmax[i+1], a[i]);

    ll i = 0, j = 0, ans = -1;
    while(i < n && j < n){
        if(Lmin[i] < Rmax[j]){
            ans = max(ans, j - i);
            j++;
        } else {
            i++;
        }
    }
    return ans;
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

    loop:
    while(t--){
        ll n;
        cin >> n;

        ll a[n];
        for(ll &x : a)
            cin >> x;

       ll res = maxIndexDiff(a,n);
       cout << res << endl;
    }

    return 0;
}
