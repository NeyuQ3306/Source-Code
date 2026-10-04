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

int priority(char c){
    if(c == '^') return 3;
    if(c == '*') return 2;
    if(c == '/') return 2;
    if(c == '+') return 1;
    if(c == '-') return 1;

    return 0;
}

void solve() {
    string ans = "";
    string s;
    getline(cin, s);

    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') st.push(s[i]);
        else if(isalpha(s[i])) ans += string(1,s[i]);
        else if(s[i] == ')'){
            while(st.top() != '('){
                ans += string(1,st.top());
                st.pop();
            }

            st.pop();
        }
        
        else{
            while(!st.empty() && priority(st.top()) >= priority(s[i])){
                ans += string(1,st.top());
                st.pop();
            }
            
            st.push(s[i]);
        }
    }

    
    while(!st.empty()){
        ans += string(1,st.top());
        st.pop();
    }
    
    cout << ans << endl;
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