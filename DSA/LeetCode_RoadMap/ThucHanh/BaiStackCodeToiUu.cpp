#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define sz size
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: Bài này giống bài dãy ngoặc đúng dài nhất nhưng điều kiện thay đổi là tìm dãy ngoặc đúng
có số lượng [ lớn nhất
- Ta sử dụng dp[i] để lưu độ dài dãy ngoặc đúng kết thúc tại i
- Khi đã có 1 dãy ngoặc đúng bất kì ta tính số dấu [ trong đoạn đó, dùng prefixsum để truy xuất nhanh
với prefix[i] = số lượng dấu [ từ 0 tới vị trí i
=> Với 1 đoạn ngoặc hợp lệ từ chỉ số l tới r thì có pre[r] - pre[l-1]
- Dùng stack để ktra đoạn ngoặc hợp lệ
*/

void solve() {
    string tmp;
    getline(cin, tmp);
    stringstream ss(tmp);
    string tok, s = "";
    while(ss >> tok) s += tok;

    int n = s.size();
    vector<int> dp(n+1,0), pref(n+1,0);

    if(s[0] == '[') pref[0] = 1;
    for(int i=1; i<n; i++){
        if(s[i] == '[') pref[i] = pref[i-1] + 1;
        else pref[i] = pref[i-1];
    }

    stack<int> st;
    int ans = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '(' || s[i] == '[') st.push(i);
        else{
            if(!st.empty() && ((s[st.top()] == '[' && s[i] == ']') || (s[st.top()] == '(' && s[i] == ')'))){
                int j = st.top();
                st.pop();

                dp[i] = i - j + 1;
                // Nếu trước dấu mở ngoặc của dãy đúng đang xét cũng là 1 dãy ngoặc đúng thì cộng dồn
                // A là dãy đúng, B là dãy đúng thì AB là dãy đúng
                if(j > 0) dp[i] += dp[j-1];

                int l = i - dp[i] + 1;
                int cnt = 0;
                if(l == 0) cnt = pref[i];
                else cnt = pref[i] - pref[l-1];
                ans = max(ans,cnt);
            }

            else{
                while(!st.empty()) st.pop();
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
              
    while(t--){
       solve(); 
    }
    return 0;
}