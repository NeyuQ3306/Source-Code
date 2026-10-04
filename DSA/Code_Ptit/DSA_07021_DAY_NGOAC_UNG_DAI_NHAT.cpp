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

/* Ý tưởng: Ta sử dụng stack để ktra dãy ngoặc hợp lệ
- Mảng dp[i] lưu độ dài dãy ngoặc đúng dài nhất kthuc tại vị tri i
- Nếu đoạn từ l->r là 1 dãy hợp lệ thì dp[r] = r - l + 1
- Nếu đoạn trước l->r là x->l-1 cũng là đoạn hợp lệ thì cộng dồn vào dp[r]
*/

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> dp(n+1,0);
    stack<int> st;
    int ans = 0;

    for(int i=0; i<n; i++){
        if(s[i] == '(') st.push(i);
        else{
            if(!st.empty()){
                int j = st.top();
                st.pop();

                dp[i] = i - j + 1;
                if(j > 0) dp[i] += dp[j-1];

                ans = max(dp[i], ans);
            }
        }
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