#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6;
ll n, m, k;
ll a[MAXN], b[MAXN];
int cnt[10];

/* Ý tưởng: Bài toán đếm cặp (x,y) thỏa mãn x^y > y^x
- Xảy ra khi và chỉ khi x < y và các trường hợp đặc biệt sau:
+ x = 0 => 0^y = 0 và y^0 = 1 nên k tồn tại (x,y)
+ x = 1 => 1^y = 1 và y^1 = y < 1 khi và chỉ khi y = 0
+ x = 2 và y = 3 sẽ là cặp đặc biệt vì 2^3 < 3^2
+ x = 2 và y = 4 k thỏa mãn vì 2^4 = 4^2

- Thuật toán: Sử dụng mảng cnt[k] để đếm số b[i] == k 
và dem(x) trả về số y thỏa mãn x
Với mỗi x (a[i]) từ mảng a:
+ Nếu x == 0 thì dem(x) = 0;
+ Nếu x == 1 thì dem(x) = cnt[0];
+ Nếu x > 1 thì:

*/

ll dem(int a){
    if(a == 0) return 0;            // x = 0 -> không có y
    if(a == 1) return cnt[0];       // x = 1 -> chỉ y = 0 thỏa
    auto it = upper_bound(b, b + m, a);
    ll ans = cnt[0] + cnt[1];       // y = 0 và y = 1 luôn thỏa
    int pos = it - b;
    ans += m - pos;                 // cộng số y > a (most y > x thỏa)
    if(a == 2) ans -= (cnt[3] + cnt[4]); // ngoại lệ x=2
    if(a == 3) ans += cnt[2];       // ngoại lệ x=3
    return ans;
}

void solve() {
    int t;
    cin >> t;

    while(t--){
        memset(cnt, 0, sizeof(cnt));
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++){
            cin >> b[i];
            if(b[i] < 5) cnt[b[i]]++;
        }


        sort(b, b + m);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += dem(a[i]);
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