#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Gọi F[i]: tổng các xâu con liên tiếp tính tới vị trí i của xâu s
VD: Cho xâu 235 = 2 + 3 + 5 + 23 + 35 + 235
F[1] = 2
F[2] = 23 + 3 = 20 + 3 + 3 = F[1] * 10 + 2 * 3
F[3] = 35 + 235 + 5 = 230 + 30 + 5 + 5 + 5 = F[2] * 10 + 3 * 5
=> F[i] thì ko tính các xâu của F[i-1]
=> CT truy hồi: F[i] = F[i-1] * 10 + i * (s[i] - '0')
=> Bài toán con nhỏ nhất: F[0] = 0;
*/

void solve() {
    string s;
    cin >> s;

    // len(s) <= 10^12
    ll F[15] = {0};
    ll ans = 0;
    s = "0" + s;
    for(int i=1; i<s.size(); i++){
        F[i] = F[i-1] * 10 + i * (s[i] - '0');
        ans += F[i];
    }

    cout << ans << endl;
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