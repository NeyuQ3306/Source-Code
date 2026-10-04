#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/
int n, x[101], a[101];
set<vector<int>> se;

bool nt(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0) return false;
    }

    return n>1;
}

void ql(int i, int bd, int sum){
    for(int j=bd; j<=n; j++){
        x[i] = a[j];
        sum += a[j];

        if(nt(sum)){
            vector<int> tmp;
            for(int u=1; u<=i; u++) tmp.push_back(x[u]);
            se.insert(tmp);
        }

        if(j+1<=n) ql(i+1,j+1,sum);
        sum -= a[j];
    }
}

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1,greater<int>());
    
    memset(x,0,sizeof(x));
    se.clear();
    x[0] = 0;

    ql(1,1,0);
    for(auto x : se){
        for(int i : x) cout << i << " ";
        cout << endl;
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