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

void solve() {
    int n,t;
    cin >> n >> t;

    set<int> st;
    queue<pii> qu;
    qu.push({n,0});
    st.insert(n);

    while(!qu.empty()){
        pii top = qu.front();
        if(top.fi == t){
            cout << top.se << endl;
            break;
        }

        qu.pop();
        if(st.find(top.fi-1) == st.end() && top.fi > 1){
            qu.push({top.fi-1, top.se+1});
            st.insert(top.fi-1);
        }

        if(st.find(top.fi*2) == st.end() && top.fi < t){
            qu.push({top.fi*2, top.se+1});
            st.insert(top.fi*2);
        }
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