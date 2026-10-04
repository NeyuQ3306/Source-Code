#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/


void solve() {
    map<char,int> mp;
    int k;
    string s;
    cin >> k >> s;
    
    for(char c : s) mp[c]++;

    priority_queue<int> pq;
    for(auto x : mp){
        pq.push(x.second);
    }

    while(k--){
        int top = pq.top();
        pq.pop();

        --top;
        pq.push(max(top,0));
    }

    ll sum = 0;
    while(!pq.empty()){
        int t = pq.top();
        sum += 1ll*t*t;
        pq.pop();
    }

    cout << sum << endl;
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