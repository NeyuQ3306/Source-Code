#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Số ngày mua lương thực tối thiểu
- Ta duyệt từ ngày 1 đến ngày s ko tính ngày chủ nhật, ta luôn chọn mua từ ngày 1 cho tới khi
lượng lương thực tích trữ >= s * m (số lương thực cần thiết để tồn tại)
- Kiểu làm trên thì có vẻ ko có tư duy tham lam lắm mà ta chỉ đi duyệt tuần tự cho tới khi gặp 
số ngày thỏa mãn mua đủ số lương thực cần thiết thì dừng
- Ta có thể làm cách khác: Tính số ngày có thể đi chợ = s - s/7 (7 ngày thì có 1 chủ nhật)
thì số lương thực tối đa có thể mua là n * (s - s/7) nếu < s * m thì return -1; ngược lại chắc 
chắn mua đủ lượng cần thiết thì số ngày tối thiêu là = s * m / n (làm tròn lên)
*/

void solve() {
    int n,s,m;
    cin >> n >> s >> m;

    int need = s * m;
    int ans = 0;

    for(int i=1; i<=s; i++){
        if(i % 7 == 0) continue;
        else{
            ++ans;
            if(ans * n >= need){
                cout << ans << endl;
                return;
            }
        }
    }

    cout << "-1" << endl;
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