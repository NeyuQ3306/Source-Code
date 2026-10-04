#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    int n,k;
    cin >> n >> k;

    int a[n+1];
    for(int i=1; i<=k; i++) cin >> a[i];

    int x = k;
    while(x > 0){
        if(x == 1){
            if(a[x] > n-k+x) break;
        }
        else{
            if(a[x] > a[x-1] + 1) break;
        }
        --x;
    }

    if(x == 0){
        for(int i = 1; i <= k; i++) cout << n - k + i << " ";
    }
    else{
        a[x]--;
        for(int j = x+1; j <= k; j++){
            a[j] = n - k + j;
        }

        for(int i = 1; i <= k; i++) cout << a[i] << " ";
    }

    cout << "\n";
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