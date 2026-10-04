#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: Cây biểu thức là một cây nhị phân trong đó mỗi node trung gian là một phép
toán, mỗi node lá là một toán hạng
- Đối với cây biểu thức, duyệt theo thứ tự trước ta sẽ được biểu thức tiền tố, 
duyệt theo thứ tự sau ta sẽ được biểu thức hậu tố, duyệt theo thứ tự giữa ta được 
biểu thức trung tố. Chú ý, cây biểu thức luôn là cây nhị phân đầy 
(mỗi node trung gian đều có hai node con).
C1: Biến đổi trực tiếp từ hậu tố sang trung tố bằng stack
C2: Xây dựng cây nhị phân và duyệt theo Inorder

=> Với input bài này tạo cây khó nên làm c1, output ko có khoảng trắng chịu đề
*/

void solve() {
    string s;
    getline(cin, s);

    stack<string> st;
    for(char c : s){
        if(isalpha(c)) st.push(string(1,c));
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            st.push(t2  + string(1,c)  + t1);
        }
    }

    cout << st.top() << endl;
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