#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6;
ll n, m, k;
ll a[MAXN], b[MAXN];

/* Ý tưởng: Vì dữ liệu bài này là n < 10^3 nên có thể dùng SelectionSort
- Mỗi lần đưa ptu nhỏ nhất lên đầu thì số swap sẽ tối thiểu
- Với dữ liệu lớn hơn ta phải dùng chu trình hoán vị sẽ cho đpt O(nlogn)

*/



void solve() {
    int t;
    cin >> t;

    while(t--){
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> a[i];

        ll ans = 0;
        for(int i=0; i<n-1; i++){
            int min_pos = i;
            for(int j=i+1; j<n; j++){
                if(a[j] < a[min_pos])
                    min_pos = j;
            }

            if(min_pos != i){
                swap(a[min_pos], a[i]);
                ++ans;
            }
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