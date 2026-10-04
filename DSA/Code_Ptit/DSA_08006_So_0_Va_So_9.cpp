#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    int n;
    cin >> n;

    queue<string> qu;
    qu.push("9");

    while(1){
        string t = qu.front();

        if(stoll(t) % n == 0){
            cout << stoll(t) << endl;
            break;
        }

        qu.pop();

        qu.push(t + "0");
        qu.push(t + "9");
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