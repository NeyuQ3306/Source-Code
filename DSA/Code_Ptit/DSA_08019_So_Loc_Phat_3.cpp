#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/


void solve() {
    int sz;
    cin >> sz;

    queue<string> qu;
    stack<string> res;
    qu.push("6");
    qu.push("8");

    while(!qu.empty()){
        string top = qu.front();
        qu.pop();

        if(top.size() > sz) continue;
        res.push(top);

        qu.push(top+"6");
        qu.push(top+"8");
    }

    cout << res.size() << endl;
    while(!res.empty()){
        cout << res.top() << " ";
        res.pop();
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