#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Bài này có cách 1 vòng for nhma khó hiểu hơn, số chiều của dp thì tùy
người làm 
- Ta sử dụng dp 2 chiều F[i][j] là xét xem với i phần tử đầu tiên có tạo thành tổng
bằng j hay ko
- Công thức truy hồi ở đây dựa theo quy tắc với mỗi phần tử đang xét ta có 2 lựa chọn
LẤY hoặc KO LẤY:
Th1, Ta KO LẤY phần tử thứ i đang xét nếu với i-1 phần tử đầu tiên đã đủ tổng j mong
muốn thì F[i][j] = F[i-1][j]
Th2, Ta LẤY phần tử này nếu i-1 phần tử đầu tiên có tổng đúng bằng j - a[i] thì khi 
thêm phần tử a[i] sẽ đủ tổng = j:  F[i][j] = F[i-1][j-a[i]]

? Tại sao ta phải sinh tất cả các tổng cho từng số lượng phần tử vì ta ko biết khi xét
phần tử trong tương lai ta sẽ cần lượng có trước j - a[i] là bao nhiêu 
? Tại sao F[n][s] đúng thì giải quyết được ycbt, ta có F[n][s] = 1 có nghĩa là với n phần
tử của mảng a có thể tạo thành tổng s, nghĩa là có 2 trường hợp là F[n-1][s] = 1 || F[n-1][s - a[n]]
Th1, F[n-1][s] = 1 nghĩa là 1 tập con của mảng a (gồm các phần tử ko liên tiếp) sẽ tạo thành tổng s được
Th2, F[n-1][s - a[n]], n-1 phần tử trước đã đủ lượng cần thiết sau khi thêm a[n] thì đủ tổng s
*/

bool F[205][40005];

void solve() {
    int n,s;
    cin >> n >> s;

    memset(F,0,sizeof(F));
    for(int i=0; i<=n; i++) F[i][0] = true;

    int a[n+1];
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            if(j - a[i] >= 0) F[i][j] = F[i-1][j-a[i]] || F[i-1][j];
            else F[i][j] = F[i-1][j];
        }
    }

    cout << (F[n][s] ? "YES" : "NO") << endl;
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