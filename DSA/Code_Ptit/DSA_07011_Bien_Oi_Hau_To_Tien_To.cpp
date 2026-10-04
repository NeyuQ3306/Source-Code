#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    string s;
    getline(cin, s);

    stack<string> st;
    for(int i=0; i<s.size(); i++){
        if(isalpha(s[i])){
            st.push(string(1,s[i]));
        }

        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string tmp = t1 + t2 + string(1,s[i]);
            st.push(tmp);
        }
    }

    string res = st.top();
    reverse(res.begin(), res.end());
    cout << res << endl;
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