#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: 

*/


int n,k,X[100], used[100];
string s;


void inkq(){
    for(int i=1; i<=n; i++)
        cout << s[X[i] - 1];
    cout << " ";
}

void Try(int i){
    for(int j=1; j<=n; j++){
        if(used[j] == 0){
            X[i] = j;
            used[j] = 1;

            if(i == n)
                inkq();
            else
                Try(i+1);

            used[j] = 0;
        }
    }
}

void solve(){
    s.clear();
    cin >> s;

    n = s.size();
    Try(1);

    cout << endl;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}