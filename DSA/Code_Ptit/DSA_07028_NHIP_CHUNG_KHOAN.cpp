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
    int n;
    cin >> n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin >> a[i];

    stack<int> st;
    for(int i=1; i<=n; i++){
        while(!st.empty() && a[i] >= a[st.top()]){
            st.pop();
        }

        if(st.empty()) cout << i << " ";
        else cout << i - st.top() << " ";
        st.push(i);
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