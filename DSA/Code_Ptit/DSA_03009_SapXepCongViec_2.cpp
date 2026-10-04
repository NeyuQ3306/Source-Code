#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng:
B1: Sắp xếp công việc theo lợi nhuận giảm dần 
B2: Đối với mỗi công việc, lựa chọn mốc tgian bắt đầu là mốc tgian lớn nhất còn
trống để hạn chế bỏ lỡ nhiều công việc nhất có thể
Ví dụ ta chọn deadline muộn nhất có thể là X thì có thể làm trong các mốc tgian
0 1 ... X-1 thì chọn X-1 để làm công việc đang xét

Nhận xét: Độ phức tạp bài này sẽ là O(n^2) vì ta mất O(nlogn) để sort mảng giảm
dần theo lợi nhuận
- Tham lam bằng cách luôn lấy deadline công việc lợi nhuận lớn nhất là mốc tgian
muộn nhất có thể = X
- Ta duyệt từ 0 1 ... X-1 để tìm mốc tgian còn trống ở phía trước để làm các công
việc có lợi nhuận cao tiếp theo
*/

void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> v; // vector rỗng
    int max_deadline = 0;
    for(int i=0; i<n; i++){
        int id, x, y;
        cin >> id >> x >> y;
        v.push_back({x, y});
        max_deadline = max(max_deadline, x);
    }

    // sort theo lợi nhuận giảm dần
    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    });

    int ans = 0;
    int cnt = 0;
    vector<int> vis(max_deadline + 1, 0); // đánh dấu mốc tgian đã sử dụng

    for(int i=0; i<n; i++){
        int x = v[i].first;
        // vòng while tìm mốc tgian gần deadline nhất để làm công việc đang xét
        while(x > 0 && vis[x]) --x;
        if(x > 0 && vis[x] == 0){
            ++cnt;
            ans += v[i].second;
            vis[x] = 1;
        }
    }

    cout << cnt << " " << ans << endl;
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