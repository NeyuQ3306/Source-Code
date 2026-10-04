#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: Xâu con chung dài nhất của 2 xâu
- Ta sử dụng dp[i][j] là độ dài xâu con chung dài nhất tại vị trí i của s và j của t
- Tại vị trí i,j ta có 2 trường hợp:
+ s[i] = t[j] thì dp[i][j] = dp[i-1][j-1] + 1;
+ s[i] != t[j] thì dp[i][j] = max(dp[i-1][j], dp[i][j-1]), lùi lại 1 vị trí để tìm độ dài
lớn nhất
- Cách làm dưới là đệ quy có nhớ, có thể làm như các bài khác là xây dựng dp trực tiếp qua
vòng for, lưu ý ở cách này là dòng 45 khi gọi tới các dequy(i1,j1) nếu đã xây dựng rồi thì return
luôn để giảm độ phức tạp thgian

*/

string s,t;
int n,m;

int dp[1005][1005];
int dequy(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    // Trường hợp 1 xâu là xâu rỗng
    if(i==0 || j==0) return 0;

    int ans = 0;
    if(s[i] == t[j]) ans = 1 + dequy(i-1,j-1);
    else ans = max(dequy(i-1,j), dequy(i,j-1));

    return dp[i][j] = ans;
}



void solve() {
    cin >> s >> t;
    n = s.size(), m = t.size();
    
    s = "@" + s;
    t = "$" + t;

    memset(dp,-1,sizeof(dp));
    cout << dequy(n,m) << endl;
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