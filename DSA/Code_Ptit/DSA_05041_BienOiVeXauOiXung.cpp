#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: 2 Bài toán số phép xoá tối thiểu, số phép chèn tối thiểu có kết quả giống nhau
là n - LPS, LPS = LCS(s, rev(s)) : xâu con chung dài nhất của s và rev(s) chính là xâu con đối
xứng dài nhất
- Khác với bài xâu đối xứng LPS(Longest Palindromic SUBSTRING) xâu con là xâu liên tiếp, ở đây
LPS(Longest Palindromic SUBSEQUENCE) ko cần phải liên tiếp 
- Vậy bài này ta chỉ cần tính xâu con chung đối xứng dài nhất rối lấy n - size là được

- Các dạng bài tương tự nhau:
1. Xâu con chung của 2 xâu LCS - Longest Common Subsequence:
- dp[i][j]: độ dài xâu con dài nhất từ vị trí i->j (ko cần liên tiếp)
if(s[i] == t[j])
    dp[i][j] = dp[i-1][j-1] + 1;
else
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

2.Xâu con đối xứng dài nhất ko cần liên tiếp LCS - Longest Palindromic Subsequence
- LPS = LCS(s, reverse(s))

3. Số bước xoá tối thiểu để xâu biến thành xâu đối xứng - Minimum deletion để thành palindrome
- min_delete = n - LPS
4. Số bước chèn tối thiểu để xâu biến thành xâu đối xứng - Minimum insertion để thành palindrome
- min_insert = n - LPS
5. Số bước xoá tối thiểu để biến 2 xâu thành giống nhau - Minimum deletion để 2 xâu giống nhau
- delete = (n - LCS) + (m - LCS)

6. Số thao tác tối thiểu để biến xâu s thành xâu t cho trước - Edit Distance
- Cho 3 thao tác insert, delete và replace hãy tìm số thao tác tối thiểu:
- dp[i][j] = số phép biến đổi ít nhất để biến S[1..i] thành T[1..j]
dp[i][j] = 1 + min(
    dp[i-1][j],      // delete
    dp[i][j-1],      // insert
    dp[i-1][j-1]     // replace
)
- Nếu ko cho phép replace thì: ans = Edit distance = n + m - 2 * LCS
*/

int dp[1005][1005];

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    string r = s;
    reverse(r.begin(), r.end());

    // Nếu chèn thêm kí tự vào đầu thì đk check là s[i] == r[j] cập nhật cho dp[i][j] qua dp[i-1][j-1]
    r = "2" + r;
    s = "3" + s;
    int ans = 0;
    memset(dp,0,sizeof(dp));

    // dp[i][i]: do dai xau con chung dai nhat trong doan i -> j
    for(int i=1; i<s.size(); i++){
        for(int j=1; j<r.size(); j++){
            if(s[i] == r[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            ans = max(ans, dp[i][j]);
        }
    }

    cout << n - ans << endl;
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