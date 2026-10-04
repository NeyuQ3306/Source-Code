#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int tinh(string a, string b, char op){
    int num1 = stoll(a);
    int num2 = stoll(b);

    if(op == '+') return num1 + num2;
    if(op == '-') return num1 - num2;
    if(op == '*') return num1 * num2;
    if(op == '/') return num1 / num2;
}

void solve() {
    string s;
    getline(cin, s);

    stack<string> st;
    for(int i=0; i<s.size(); i++){
        if(isdigit(s[i])){
            st.push(string(1,s[i]));
        }

        else{
            string t1 = st.top();
            // cout << t1 << endl;
            st.pop();
            string t2 = st.top();
            // cout << t2 << endl;
            st.pop();

            int tmp = tinh(t2,t1,s[i]);
            st.push(to_string(tmp));
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