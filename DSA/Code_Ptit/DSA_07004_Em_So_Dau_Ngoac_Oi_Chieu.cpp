#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Phải đối chiều nếu rơi vào 2 trường hợp
Th1, Thừa dấu ), xét ngay khi duyệt s nếu stack rỗng thì phải đổi chiều luôn và push
vào stack vì k được thêm dấu mới
Th2, Thừa dấu (, sau khi duyệt xong s mà stack ko rỗng thì phải đổi chiều st.size()/2
Vd: Sau khi duyệt trong stack còn (((( thì chỉ có cách đổi chiều thành (())
- s.length() chẵn 
*/

void solve() {
    string s;
    getline(cin, s);

    int ans = 0;
    stack<int> st;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') st.push(i);
        else{
            if(st.empty()){
                ++ans;
                st.push(i);
            }

            else st.pop();
        }
    }

    cout << ans + st.size()/2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
              
    while(t--){
       solve(); 
    }
    return 0;
}