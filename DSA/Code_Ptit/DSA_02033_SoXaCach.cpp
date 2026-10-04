#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];
int used[100], X[100];

/* Ý tưởng: 

*/

void inkq(){
    bool check = true;
    for(int i=1; i<n; i++){
        if(abs(X[i] - X[i+1]) == 1){
            check = false;
            break;
        }
    }

    if(check){
        for(int i=1; i<=n; i++)
            cout << X[i];
        cout << endl;
    }
}

void Try(int i){
    for(int j=1; j<=n; j++){
        if(used[j] == 0){
            X[i] = j;
            used[j] = 1;

            if(i==n)
                inkq();
            else
                Try(i+1);

            used[j] = 0;

        }
    }
}

void solve(){
    cin >> n;
    Try(1);
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