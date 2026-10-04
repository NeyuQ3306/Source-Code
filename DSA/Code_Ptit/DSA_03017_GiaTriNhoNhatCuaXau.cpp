#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng:

*/

void solve() {
    int q;
    string s;
    cin >> q >> s;

    map<char,int> mp;
    for(char c : s) mp[c]++;

    priority_queue<int,vector<int>> pq;
    for(pair<char,int> p : mp) pq.push(p.second);

    ll ans = 0;
    while(q--){
        int tmp = pq.top();
        --tmp;
        pq.pop();
        pq.push(tmp);
    }

    // while(!pq.empty()){
    //     cout << pq.top() << " ";
    //     pq.pop(); 
    // }

    // cout << endl;

    while(!pq.empty()){
        ans += pq.top() * pq.top();
        pq.pop();
    }

    cout << ans << endl;
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