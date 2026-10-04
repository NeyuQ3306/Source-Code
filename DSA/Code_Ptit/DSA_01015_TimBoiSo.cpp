#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Bài này ta có 2 cách làm:
Cách 1: Đúng chủ đề sinh kế tiếp - quay lui: Ta sinh tất cả các số chỉ chứa 0 và 9
trong khoảng giới hạn của long long, lưu vào vector và sort tăng dần; duyệt tuần tự
để tìm ans

Cách 2: Dùng hàng đợi, ban đầu ta lưu 9 vào hàng đợi nếu ko phải bội số của n thì ta xóa
đi và thêm vào 90 và 99
=> tư tưởng là khi xét mỗi x của hàng đợi, nếu chia hết ta in ra và đó là kq cần tìm;
ngược lại xóa x và thêm vào x*10 và x*10 + 9 (đúng thứ tự này mới tìm được số nhỏ nhất là bội số)

=> Đánh giá: Cách 2 nhanh hơn nhiều vì tính chất của hàng đợi cho ta tìm kiếm theo chiều rông
BFS, phù hợp với các bài toán đếm số bước biến đổi tối thiểu để tìm ra số mong muốn

*/

void solve() {
    cin >> n;

    queue<ll> qu;
    qu.push(9);

    bool check = true;
    while(check){
        ll tmp = qu.front();
        if(tmp % n == 0){
            cout << tmp << endl;
            check = false;
            return;
        }

        else{
            qu.pop();
            qu.push(tmp*10);
            qu.push(tmp*10 + 9);
        }
    }
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