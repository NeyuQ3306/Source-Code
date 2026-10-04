#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng:

*/

void solve() {
    int n,m,k;
    cin >> n >> m >> k;

    int a[n], b[m], c[k];
    for(int &x : a) cin >> x;
    for(int &y : b) cin >> y;
    for(int &z : c) cin >> z;

    int i = 0, j = 0, h = 0;
    bool check = false;

    while(i<n && j<m && h<k){
        if(a[i] == b[j] && b[j] == c[h]){
            cout << a[i] << " ";
            ++i,++j,++h;
            check = true;
        }

        else{
            if(a[i] < b[j]) ++i;
            else if(b[j] < c[h]) ++j;
            else ++h;
        }
    }

    if(!check) cout << "NO" << endl;
    cout << endl;
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