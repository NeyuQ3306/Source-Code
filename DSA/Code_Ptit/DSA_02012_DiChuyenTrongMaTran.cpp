#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: 

*/


int n,m,k,X[100], a[100][100], dp[100][100];
// vector<vector<int>> res;


// void luukq(){
//     vector<int> tmp;
//     ll sum = 0;
//     for(int i=1; i<=n; i++){
//         if(X[i]){
//             sum += a[i];
//             tmp.push_back(a[i]);
//         }
//     }

//     if(sum == k)
//         res.push_back(tmp);
// }

// void Try(int i){
//     for(int j=0; j<=1; j++){
//         X[i] = j;

//         if(i == n)
//             luukq();
//         else
//             Try(i+1);
//     }
// }

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
            cin >> a[i][j];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1 || j==1)
                dp[i][j] = 1;

            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << dp[n][m];

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