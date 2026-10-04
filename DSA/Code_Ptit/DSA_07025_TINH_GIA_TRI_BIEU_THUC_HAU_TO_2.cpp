#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tinh(ll n1, ll n2, string op){
    if(op == "+") return n1 + n2;
    if(op == "-") return n1 - n2;
    if(op == "*") return n1 * n2;
    if(op == "/") return n1 / n2;
    return 0;
}

void solve() {
    int n;
    cin >> n;
    cin.ignore();

    string s;
    getline(cin, s);

    string token;
    stringstream ss(s);
    stack<ll> st;

    while(ss >> token){
        if(token == "–") token = "-"; 

        if(token == "+" || token == "-" || token == "*" || token == "/"){
            ll t1 = st.top(); st.pop();
            ll t2 = st.top(); st.pop();

            st.push(tinh(t2, t1, token)); 
        }
        else{
            st.push(stoll(token));
        }
    }

    cout << st.top() << endl;
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