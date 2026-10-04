#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n;
int a[100005], T[50005], G[50005];
void solve() {
    cin >> n;
    memset(a,0,sizeof(a));
    memset(T,0,sizeof(T));
    memset(G,0,sizeof(G));

    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        T[i] = 1;
        for(int j=1; j<i; j++){
            if(a[j] <= a[i]) T[i] = max(T[i], T[j] + 1);
        }
    }

    for(int i=n; i>=1; i--){
        G[i] = 1;
        for(int j=n; j>i; j--){
            if(a[j] <= a[i]) G[i] = max(G[i], G[j] + 1);
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, T[i] + G[i] - 1);
    }

    cout << ans << endl;
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