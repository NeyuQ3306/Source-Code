#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    string s;
    cin >> s;

    if(s.size() == 0) cout << "YES\n";
    else{
        stack<char> st;
        bool ok = true;

        for(char c : s){
            if(c == '(' || c == '[' || c == '{') st.push(c);
            else{
                if(st.empty()){
                    ok = false;
                    break;
                }

                char t = st.top();
                if((c == ')' && t != '(')
                || (c == ']' && t != '[')
                || (c == '}' && t != '{')){
                    ok = false;
                    break;
                }

                st.pop();
            }
        }

        if(ok && st.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
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