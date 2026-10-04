#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Note 1 số dạng bài toán QHĐ thường gặp:
1. Được dùng a[i] nhiều lần và ko tính hoán vị trùng nhau
- Các bài toán như cái túi cho phép lấy 1 đồ nhiều lần, mô hình bài
toán coin: cho mảng a là giá trị các đồng xu tính số cách lấy tổng các
đồng xu = s
- Code: Ta có thể cài đặt mảng dp 2 chiều với 1 chiều đánh dấu là đồ vật
hay đồng xu thứ mấy đang xét và chiều còn lại là các giá trị j = 0->s hoặc
tối ưu bằng mảng 1 chiều: bỏ chiều đánh dấu đồ vật vì ta được sử dụng nhiều lần
for(int i=1; i<=n; i++){
    for(int j=0; j<=s; j++){
        dp[i][j] = {dp[i][j-a[i]], dp[i-1][j]};
    }
}

for(int i=1; i<=n; i++){
    for(int j=0; j<=s; j++){
        dp[j] = {dp[j-a[i]], dp[j]};
    }
}

2. Ko được phép dùng a[i] nhiều lần và ko tính hoán vị trùng nhau
- Các bài toán như bài toán cái túi 0-1, dãy con có tổng bằng S
- Code: Tối ưu bằng 1 chiều thì phải đổi chiều duyệt s
for(int i=1; i<=n; i++){
    for(int j=0; j<=s; j++){
        dp[i][j] = {dp[i-1][j-a[i]], dp[i-1][j]};   
    }
}

for(int i=1; i<=n; i++){
    for(int j=s; j>=1; j--){
       // code;  
    }
}

- Điểm rất hay của cách duyệt s ngược lại là khi ta tính dp[i][j] = {dp[i-1][j-a[i]], dp[i-1][j]} thực chất
ta chỉ quan tâm đến i ngay trước nó là i-1 nên k cần phải lưu lại. Việc duyệt s ngược lại giúp ta thực hiện 
việc đó, ví dụ khi tính dp[2][7] = {dp[1][7-5], dp[1][7]} với a[2] = 5 thì tương ứng dp[7] = {dp[2], dp[7]}
với dp[2], dp[7] ở vế phải ứng với vòng for i=1 và dp[7] ở vế trái ứng với i=2
- Việc duy trì thêm 1 chiều để xét xem vật đang xét là vật thứ mấy có tác dụng trong bài toán 1 đồ được lấy 1 
lần thì việc duyệt ngược s sẽ giúp làm việc đấy

3. Được dùng a[i] nhiều lần và có tính hoán vị trùng lặp
- Các bài toán như bậc thang, mô hình bài toán coin: Cho mảng a gồm giá trị các 
đồng xu, tổng s cho trước hỏi có bao nhiêu cách lấy tổng giá trị các đồng xu sao cho
tổng đó = s có tính hoán vị: (2 2 5), (2 5 2) là 2 cách
- Code:
for(int i=1; i<=s; i++){
    for(int j=1; j<=n; j++){
        // code;
    }
}

QUAN TRỌNG: Với bài toán k tính hoán vị ta duyệt n trước, có tính hoán vị ta lại duyệt s trước
=> Với bài toán này thực chất là bài toán mô hình coin có tính hoán vị và được sử dụng nhiều lần
ta giải như dạng 3
*/


int n,k;
int a[1005], dp[1005];
void solve() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];

    memset(dp,0,sizeof(dp));
    
    // dp[i]: số cách để tạo ra tổng i
    dp[0] = 1;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            if(i >= a[j]){
                // ta coi đồng xu cuối có giá trị a[j] thì cần số cách tạo ra tổng i-a[j]
                dp[i] += dp[i-a[j]];
                dp[i] %= mod;
            }
        }
    }
    
    cout << dp[k] << endl;


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