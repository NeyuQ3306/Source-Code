#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];
ll used[MAXN][MAXN];

ll ans = 0;

/* Ý tưởng:
CHƯA XONG !
*/

void loang(ll i, ll j){
    used[i][j] = true;

    ll max_v = LLONG_MIN;
    ll col = 0;

    // Ta duyệt các cột của hàng tiếp theo để tìm phần tử lớn nhất mà cột đó chưa sử dụng
    for(int k=1; k<=n; k++){
        if(!used[i+1][k]){
            if(a[i+1][k] > max_v){
                max_v = a[i+1][k];
                col = k;
            }
        }
    }

    ans += max_v;
    if(i+1 <= n && j <= n) loang(i+1, col);
}

void solve() {
    ans = 0;
    memset(a,0,sizeof(a));
    memset(used,0,sizeof(used));

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }

    // max_element trả về iterator
    ll *p = max_element(a[1] + 1, a[1] + n + 1);
    ll col = p - a[1]; // chỉ số j của phần tử max hàng 1
    
    // Ta loang từ vị trí max của hàng đầu tiên tới các ô used[i] = 0;
    loang(1,col);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
              
    while(t--){
       solve(); 
    }
    return 0;
}