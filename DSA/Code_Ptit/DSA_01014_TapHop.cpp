#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: 

*/


int n,m,k,X[100], a[100], used[100];
bool check;
ll ans = 0;


void inkq() {
    ll sum = 0;
    for(int i=1; i<=k; i++){
        sum += X[i];
    }

    if(sum == m)
        ++ans;
}


void Try(int i){
    for(int j=X[i-1]+1; j<=n-k+i; j++){
        X[i] = j;
        if(i==k)
            inkq();
        else
            Try(i+1);
    }
    
}


void solve(){
    ans = 0;
    memset(X,0,sizeof(X));

    cin >> n >> k >> m;
    if(n==0 && m==0 && k==0){
        check = false;
        return;
    }

    else{
        Try(1);
        cout << ans << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    check = true;

    while(check){
        solve();
    }
    return 0;
}