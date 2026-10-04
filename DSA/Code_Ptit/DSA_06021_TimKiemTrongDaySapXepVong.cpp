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
        int X;
        cin >> n >> X;

        for(int i=0; i<n; i++)
            cin >> a[i];

        int l1 = 0, r1 = n-1, l2 = 0, r2 = n-1;
        for(int i=0; i<n-1; i++){
            if(a[i+1] < a[i]){
                r1 = i, l2 = i+1;
            }
        }

        int ans = -1;
        while(l1<=r1){
            int mid = (l1 + r1) / 2;
            if(a[mid] == X){
                ans = mid + 1;
                break;
            }

            else if(a[mid] < X)
                l1 = mid + 1;

            else
                r1 = mid - 1;
        }

        while(l2<=r2){
            int mid = (l2 + r2) / 2;
            if(a[mid] == X){
                ans = mid + 1;
                break;
            }

            else if(a[mid] < X)
                l2 = mid + 1;

            else
                r2 = mid - 1;
        }


        cout << ans << endl;
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