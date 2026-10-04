#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Mảng đã cho là 1 hoán vị của tập từ 1 2 ... n, muốn số phép hoán đổi vị trí là ít nhất
ta chỉ cần tìm đoạn tăng dài nhất các phần tử là liên tiếp nhau = max_len
- Kq của bài toán là: n - max_len (mỗi phần tử còn lại chỉ phải di chuyển 1 lần về đầu hoặc cuối)
- pos[a[i]] = i : lưu lại vị trí của giá trị a[i], nếu pos[a[i]] < pos[a[i+1]] thì nó thỏa mãn
là 1 đoạn giá trị liên tiếp tăng dần (k cần phải liền kề trong mảng a mà là liền kề về giá trị)
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1), pos(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }

    int cur = 1, best = 1;
    for(int i = 1; i < n; i++){
        if(pos[i] < pos[i+1])
            cur++;
        else
            cur = 1;
        best = max(best, cur);
    }

    cout << n - best << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
              
    while(t--){
       solve(); 
    }
    return 0;
}