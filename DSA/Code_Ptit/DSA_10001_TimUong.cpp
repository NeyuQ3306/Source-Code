#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Dfs trên lưới - Quay lui thử tất cả các đường, cắt nhánh nếu số lần đổi hướng lớn hơn 2
- Đọc vào mảng char a, ghi lại vị trí bắt đầu, kết thúc
- Bắt đầu Try(s1,s2,-1,0) với s1,s2 vị trí ô bắt đầu, -1 là giá trị k_pre, 0 là số lần đổi hướng
- Dfs trên lưới ở đây cho loang tới 4 ô xung quanh ta quy ước k=0,k=1,k=2,k=3 tương ứng với các 
hương Trái, Lên, Phải, Xuống. Nếu hàm quay lui hiện tại có k = k_pre thì nghĩa là ko đổi hướng,
ngược lại phải tăng biến đếm đổi hướng lên
- Cắt nhánh khi số lần đổi hướng > 3 vì ta bắt đầu từ k = -1 khi gọi Try lần đầu đã tính là 1 lần
đổi hướng, dùng thêm biến flag để đánh dấu khi đã loang tới điểm kết thúc
*/

char a[1001][1001];
int di[4] = {0,-1,0,1};
int dj[4] = {-1,0,1,0};
int n,m;
int s1,s2,t1,t2;
int cnt = 0;
bool found;

void Try(int i, int j, int pre_k, int cnt){
    if(found) return;
    if(cnt > 3) return;
    if(i == t1 && j == t2){
        found = true;
        return;
    }


    for(int k=0; k<4; k++){
        int i1 = i + di[k];
        int j1 = j + dj[k];

        if(i1>0 && i1 <= n && j1>0 && j1<=m && a[i1][j1] != '*'){
            if(k == pre_k) Try(i1,j1,k,cnt);
            else Try(i1,j1,k,cnt+1);
        }
    }
}

void solve() {
    cin >> n >> m;
    found = false;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];

            if(a[i][j] == 'S'){
                s1 = i, s2 = j;
            }

            if(a[i][j] == 'T'){
                t1 = i, t2 = j;
            }
        }
    }

    Try(s1,s2,-1,0);
    if(found && cnt <= 3) cout << "YES\n";
    else cout << "NO\n";
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