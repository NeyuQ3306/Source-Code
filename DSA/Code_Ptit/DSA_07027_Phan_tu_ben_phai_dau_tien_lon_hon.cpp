#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define sz size
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

    int a[n], b[n];
    for(int &x : a)
        cin >> x;

    stack<int> st;
    for(int i=0; i<n; i++){
        if(st.empty()){
            st.push(i);
        }

        else{
            while(!st.empty() && a[st.top()] < a[i]){
                b[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }

    while(!st.empty()){
        b[st.top()] = -1;
        st.pop();
    }

    for(int x : b) cout << x << ' ';
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