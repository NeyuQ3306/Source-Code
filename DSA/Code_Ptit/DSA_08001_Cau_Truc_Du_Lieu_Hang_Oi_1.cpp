#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    int q;
    cin >> q;

    queue<int> qu;
    while(q--){
        int lc;
        cin >> lc;

        if(lc == 1){
            cout << qu.size() << endl;
        }

        if(lc == 2){
            cout << (qu.empty() ? "YES\n" : "NO\n");
        }

        if(lc == 3){
            int x;
            cin >> x;
            qu.push(x);
        }

        if(lc == 4){
            if(!qu.empty()) qu.pop();
        }

        if(lc == 5){
            if(!qu.empty()) cout << qu.front() << endl;
            else cout << -1 << endl;
        }

        if(lc == 6){
            if(!qu.empty()) cout << qu.back() << endl;
            else cout << -1 << endl;
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