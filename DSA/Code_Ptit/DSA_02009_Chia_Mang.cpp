#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,k,x[101],a[101],s,cnt;
bool ok, used[101];

void ql(int i, int bd, int sum, int cnt){
    if(cnt == k){
        ok = true;
        return;
    }

    for(int j=bd; j<=n && !ok; j++){
        if(!used[j]){
            x[i] = j;
            used[j] = true;

            if(sum + a[j] == s){
                ql(i+1,1,0,cnt+1);
            } else{
                ql(i+1,j+1,sum+a[j],cnt);
            }

            used[j] = false;
        }
    }
}

void solve() {
    cin >> n >> k;
    memset(used,false,sizeof(used));
    ok = false;
    cnt = 0;
    memset(x,0,sizeof(x));

    for(int i=1; i<=n; i++) cin >> a[i];
    s = accumulate(a+1,a+n+1,0);

    if(s%k != 0) cout << "0" << endl;
    else{
        s /= k;
        ql(1,1,0,0);

        cout << (ok ? 1 : 0) << endl;
    }
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