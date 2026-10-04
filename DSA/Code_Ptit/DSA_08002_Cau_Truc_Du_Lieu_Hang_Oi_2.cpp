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
        string lc;
        cin >> lc;

        if(lc == "PUSH"){
            int x;
            cin >> x;
            qu.push(x);
        }

        if(lc == "POP"){
            if(!qu.empty()) qu.pop();
        }

        if(lc == "PRINTFRONT"){
            if(!qu.empty()) cout << qu.front() << endl;
            else cout << "NONE" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
              
    while(t--){
       solve(); 
    }
    return 0;
}