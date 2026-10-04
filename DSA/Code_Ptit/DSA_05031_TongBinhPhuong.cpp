#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Lấy hoặc ko lấy
- Ta có F[i]: số lượng số hạng ít nhất của tổng bình phương các số nhỏ hơn i sao cho tổng = i
VD: 20 = 1^2 + 1^2 + .... + 1^2 = 2^2 + F[16] = 3^2 + F[11] = 4^2 + F[4]
- Tư tưởng lấy hoặc ko lấy, ta xét tất cả các số j=1 -> <= sqrt(i) xem có lấy nó vào tổng bình 
phương ko
    + Lấy thì F[i] = F[j*j] + F[i - j*j] = 1 + F[i - j*j]
    + Ko lấy thì F[i] = F[i]
- Ta duyệt tất cả các j xem trường hợp nào cho F[i] min là kết quả
=> CT truy hồi: F[i] = min(F[i], 1 + F[i - j*j])
=> Bài toán con nhỏ nhất: F[1] = 1
*/

void solve() {
    int n;
    cin >> n;

    int F[n+1] = {0};
    F[1] = 1;

    for(int i=2; i<=n; i++){
        F[i] = i;
        for(int j=1; j<=sqrt(i); j++){
            F[i] = min(F[i], 1 + F[i - j*j]);
        }
    }

    cout << F[n] << endl;
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