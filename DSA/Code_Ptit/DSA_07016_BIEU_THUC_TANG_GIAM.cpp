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

    stack<int> st;
    for(int i=0; i<=s.size(); i++){
        st.push(i+1);
        if(s[i] == 'I' || i == s.size()){
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
        }
    }
    cout << endl;
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