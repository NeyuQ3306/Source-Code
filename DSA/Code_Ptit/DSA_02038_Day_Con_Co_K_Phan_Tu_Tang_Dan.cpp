#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/
int n,k;
int x[101], a[101];

void ql(int i){
    for(int j=x[i-1]+1; j<=n-k+i; j++){
        x[i] = j;
        if(i==k){
            for(int z=1; z<=k; z++) cout << a[x[z]] << " ";
            cout << endl;
        }
        else ql(i+1);
    }
}

void solve() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);

    ql(1);
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