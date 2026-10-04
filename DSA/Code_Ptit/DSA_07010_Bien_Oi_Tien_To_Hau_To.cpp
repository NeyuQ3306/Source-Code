#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    string s;
    cin >> s;

    stack<string> st;
    for(int i=s.size()-1; i>=0; i--){
        if(isalpha(s[i])) st.push(string(1,s[i]));
        else{
            string tmp = "";
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            tmp += t1 + t2 + string(1,s[i]);
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