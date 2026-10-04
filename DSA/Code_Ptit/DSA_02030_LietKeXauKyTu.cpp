#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: Tổ hợp chập k của n có lặp 

*/


int n,m,k,X[100], a[100], dp[100][100];
int cheoxuoi[100], cheonguoc[100], cot[100];
vector<string> res;
ll ans = 0;

void inkq(){
    for(int i=1; i<=k; i++){
        cout << (char)(64 + X[i]);
        // cout << X[i] << " ";
    }
    cout << endl;
}

void Try(int i){
    for(int j=X[i-1]; j<=n; j++){
        X[i] = j;

        if(i==k)
            inkq();
        else
            Try(i+1);
    }
}


void solve(){
    char c;
    cin >> c >> k;

    n = c - 'A' + 1;
    X[0] = 1;
    Try(1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}