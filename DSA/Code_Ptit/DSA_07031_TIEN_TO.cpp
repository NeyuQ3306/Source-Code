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

ll tinh(ll a, ll b, string op){
    if(op == "+") return a + b;
    if(op == "-") return a - b;
    if(op == "*") return a * b;
    if(op == "/") return a / b;

    return 0;
}

void solve() {
    int n;
    cin >> n;
    cin.ignore();

    string s;
    getline(cin,s);
    stringstream ss(s);
    string token;

    vector<string> tok;
    while(ss >> token){
        if(token == "–") token = "-";
        tok.push_back(token);
    }

    stack<ll> st;
    for(int i=tok.size()-1; i>=0; i--){
        string word = tok[i];

        if(word == "+" || word == "-" || word == "*" || word == "/"){
            ll a = st.top(); st.pop();
            ll b = st.top(); st.pop();

            st.push(tinh(a,b,word));
        }

        else{
            st.push(stoll(word));
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