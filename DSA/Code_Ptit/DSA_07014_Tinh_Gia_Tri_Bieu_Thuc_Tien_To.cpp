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
    ll u = stoll(a);
    ll v = stoll(b);

    if(op == '+') return u + v;
    if(op == '-') return u - v;
    if(op == '*') return u * v;
    if(op == '/') return u / v;
}

void solve() {
    string s;
    getline(cin, s);

    stack<string> st;
    for(int i=s.size()-1; i>=0; i--){
        if(isdigit(s[i])) st.push(string(1,s[i]));
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            int tmp = tinh(t1,t2,s[i]);
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