#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

/* Ý tưởng: Gấp đôi dãy số
- Ta có quy luật để tính số ở vị trí thứ k = số lần k chia hết cho 2 + 1
- Ta có các nhận xét:
+ Sau N bước biến đổi thì độ dài dãy là 2^N - 1
+ Mọi vị trí lẻ đều = 1, số > 1 chỉ xuất hiện ở vị trí chẵn
+ Mỗi lần ta chia k là cắt bỏ đi 1 lần gấp đôi = lùi lại bước thứ N-1 
=> khi ko chia được nữa thì đã đến đúng bước xuất hiện vị trí k và có giá trị bằng số lần đã chia đôi + 1
*/



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        ll n,k;
        cin >> n >> k;

        ll ans = 0;
        while(k%2==0){
            ++ans;
            k/=2;
        }

        cout << (char)(ans + 1 + 64) << endl;
    }

    return 0;
}
