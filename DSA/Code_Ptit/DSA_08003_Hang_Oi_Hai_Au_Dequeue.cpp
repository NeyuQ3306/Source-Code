#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    int q;
    cin >> q;

    deque<int> dq;
    while(q--){
        string lc;
        cin >> lc;

        if(lc == "PUSHBACK"){
            int x;
            cin >> x;
            dq.push_back(x);
        }

        if(lc == "PUSHFRONT"){
            int x;
            cin >> x;
            dq.push_front(x);
        }

        if(lc == "PRINTFRONT"){
            if(!dq.empty()) cout << dq.front() << endl;
            else cout << "NONE" << endl;
        }

        if(lc == "PRINTBACK"){
            if(!dq.empty()) cout << dq.back() << endl;
            else cout << "NONE" << endl;
        }

        if(lc == "POPFRONT"){
            if(!dq.empty()) dq.pop_front();
        }

        if(lc == "POPBACK"){
            if(!dq.empty()) dq.pop_back();
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