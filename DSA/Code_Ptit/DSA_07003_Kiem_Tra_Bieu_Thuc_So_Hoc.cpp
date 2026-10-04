#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    string s;
    getline(cin,s);

    stack<char> st;

    for(char c : s){
        if(c != ')'){
            st.push(c);
        }

        else{
            bool ok = false;
            while(!st.empty()){
                char c = st.top();
                st.pop();

                if(c == '(') break;
                if(c == '*' || c == '+' || c == '-' || c == '/') ok = true;
            }

            if(!ok){
                 cout << "Yes\n";
                 return;
            }
        }
    }

    cout << "No\n";
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