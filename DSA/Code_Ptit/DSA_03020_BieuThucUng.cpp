#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Mục tiêu là cố gắng kéo các ] lên phía đầu
- Ta dùng stack để lưu lại các dấu [, nếu gặp dấu ] ta có 2 trường hợp:
Th1, Phía trước đó đã có dấu [ tạo thành 1 cặp hợp lệ (nếu stack ko rỗng)
Th2, Stack rỗng ta phải thực hiện phép đổi chỗ cho dấu ] gần nhất ở bên phải

- Các biến thể của bài này như đổi chỗ về đầu hoặc cuối hay đổi chỗ bất kì thì ta làm như sau:
+ Đổi về đầu hoặc cuối giống bài Sắp xếp tham lam: Ta tìm độ dài dãy con (ko cần liên tiếp) dài 
nhất thỏa mãn ycbt thì số phép biến đổi tối thiểu là: s.size() - max_len
+ Bài đổi chỗ bất kì thì ta duy trì biến balance (++ nếu gặp [ và -- nếu gặp), khi balance < 0
nghĩa là đang thừa ] ta phải đổi chỗ 1 lần: ans = số lần balance < 0
*/

void solve() {
    string s;
    cin >> s;

    stack<char> st;
    ll ans = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '[') st.push(s[i]);
        else{
            if(!st.empty()) st.pop();
            else{
                int j=i;
                while(s[j] == ']') ++j; // tìm vị trí ] gần nhất
                ans += j - i; // số bước phải thao tác đổi liền kề
                swap(s[i], s[j]);
                st.push(s[i]);
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