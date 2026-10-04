#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Biến đổi tiền tố sang trung tố
- Duy trì 1 stack, gặp toán hạng thì đẩy vào, gặp toán tử thì lấy ra 2 toán hạng ở đầu và chèn
toán tử vào giữa
- Thêm 2 dấu đóng mở ngoặc và đẩy lại vào stack, lặp cho tới khi hết biểu thức tiền tố phần tử
trong stack sẽ là biểu thức trung tố
*/

void solve() {
    string s;
    cin >> s;

    stack<string> st;
    for(int i=s.size()-1; i>=0; i--){
        // nếu đề có chữ số thì dùng isalnum để check
        if(isalpha(s[i])){
            // st.push(to_string(s[i])); cẩn thận to_string của kí tự sẽ ra mã ASCII
            st.push(string(1, s[i]));
        }

        else{
            string tmp = "(";
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            tmp += t1 + string(1,s[i]) + t2 + ")";
            st.push(tmp);
        }
    }

    string ans = st.top();
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