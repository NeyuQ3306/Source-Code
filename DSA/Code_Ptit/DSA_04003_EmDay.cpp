#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 123456789;
const int MAXN = 101;
ll n, m, cnt, k;
ll aa[MAXN][MAXN], a[MAXN];
vector<string>res;
bool check_final = false;

/* Ý tưởng: Bài đếm dãy bản chất là bài phân hoạch n nhưng có xét đến thứ tự
- Vì n lớn nên k thể làm bằng phương pháp sinh
- Ta làm dựa trên ý tưởng bài chia kẹo Euler: 
+ Chia n thành n cái kẹo, ta tìm xem có bao nhiêu cách để chia cho k đứa trẻ
mỗi đứa ít nhất 1 cái, k = 1,2,...,n
+ Với n cái kẹo ta có n-1 khoảng cách giữa nó, tìm số cách đặt các vách ngăn vào
n-1 khoảng trống ta sẽ có tương ứng số phân hoạch của n
+ Kết quả bài toán là
0Cn-1 + 1Cn-1 + 2Cn-2 + ... + n-1Cn-1 = 2^(n-1)
*/

ll binpow(ll a, ll b, ll c){
    if(b==0)
        return 1;
    else{
        ll X = binpow(a,b/2,c);

        if(b%2==0)
            return (X%c * X%c) % c;
        else
            return (X%c * X%c * a%c) % c;
    }
}



void solve() {
    cin >> n;
    cout << binpow(2,n-1,mod) << endl;

}

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
        solve();
    }

    return 0;
}