#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    stack<int> st;

    for(int i=0; i<n; i++){
        if(s[i] == ')' && !st.empty() && s[st.top()] == '(') st.pop();
        else st.push(i);
    }

    cout << n - st.size() << endl;
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