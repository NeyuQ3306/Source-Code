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

void inkq(){
    ++ans;
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
    ans = 0;
    cin >> n;
    Try(1);

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