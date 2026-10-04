#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Ta tham lam theo ý tưởng muốn số càng bé => càng ít chữ số => lấy chữ số lớn hơn : 7
- Ta giải pt: 4x + 7y = n, duyệt y giảm dần để lấy số lượng nhiều nhẩt
- In ra số lượng chữ số 4 trước để là số nhỏ nhất có thể
*/

void solve() {
    int n;
    cin >> n;

    bool check = false;
    for(int y=n/7; y>=0; y--){
        int x = (n - y*7) / 4;
        if(4 * x + y * 7 == n){
            for(int i=1; i<=x; i++) cout << 4;
            for(int j=1; j<=y; j++) cout << 7;
            check = true;
            break;
        }
   }

   if(check == false) cout << "-1";
   cout << endl;
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