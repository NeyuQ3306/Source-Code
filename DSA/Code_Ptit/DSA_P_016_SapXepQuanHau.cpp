#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: 

*/


int n,m,k,X[100], a[100][100], dp[100][100];
int cheoxuoi[100], cheonguoc[100], cot[100];
vector<vector<int>> res;
ll ans = 0;
int test = 0;

void inkq(){
    ll sum = 0;
    for(int i=1; i<=n; i++)
        sum += a[i][X[i]];

    ans = max(ans, sum);
}

void Try(int i){
    for(int j=1; j<=n; j++){
        if(cheoxuoi[i-j+n] == 0 && cheonguoc[i+j-1] == 0 && cot[j] == 0){
            X[i] = j;
            cot[j] = 1, cheoxuoi[i-j+n] = 1, cheonguoc[i+j-1] = 1;
 
            if(i == n)
                inkq();

            else
                Try(i+1);

            cheoxuoi[i-j+n] = 0, cheonguoc[i+j-1] = 0, cot[j] = 0;
        }
    }
}

void solve(){
    ++test;
    ans = 0;
    n = 8;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }

    Try(1);

    cout << "Test " << test << ": ";
    cout << ans;

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