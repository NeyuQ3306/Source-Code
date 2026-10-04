#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
ll n, m, k = 3;
ll a[MAXN][5], dp[MAXN][5];
ll C[1005];

/* Ý tưởng: Bài này nếu với dữ liệu n lớn hơn ta ko thể làm bằng cách dưới với độ
phức tạp O(n^2) được mà phải tối ưu xuống O(nlogn) bằng cách sử dụng binarysearch
- Ta sử dụng mảng v[i]: phần tử cuối cùng nhỏ nhất có thể của dãy con tăng dần có độ dài i+1
- Ta duyệt qua các phần tử a[i], nếu a[i] lớn hơn mọi phần tử trong vector v thì 
push vào; else thì tìm phần tử đầu tiên >= a[i] và thay thế nó
- Ta sẽ có kq độ dài dãy con tăng dài nhất = v.size()
- Code:
    cin >> n;
    ll a[n];
    for(ll &x : a)
        cin >> x;

    vector<int> v;
    for(int i=0; i<n; i++){
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if(it == v.end()) v.push_back(a[i]);
        else *it = a[i];
    }

    cout << v.size() << endl;

- Giải thích tại sao cách này lại đúng? Với mỗi phần tử v[i] là phần tử cuối cùng nhỏ nhất có thể
của các dãy con tăng dần có độ dài i+1, khi có 1 phần tử a[i] lớn hơn thì các dãy con này có thể tăng độ
dài lên 1 và nếu có thể tối ưu bằng cách giảm phần tử cuối cùng này nhỏ đi nữa thì càng có cơ hội mở rộng
thêm dãy nên mới thực hiện câu lệnh: else *it = a[i];
*/

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    ll a[n], dp[n];

    for(ll &x : a)
        cin >> x;

    for(int i=0; i<n; i++)
        dp[i] = 1;

    // dp[i] độ dài dãy con tăng ngặt dài nhất kthuc tại i

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << *max_element(dp,dp+n) << endl;

    return 0;
}