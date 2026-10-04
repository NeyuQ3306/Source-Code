#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
ll n, m, cnt, k;
ll a[MAXN], b[MAXN];
vector<string>res;
bool check_final = false;

/* Ý tưởng:
*/

void merge(){
    int i=1, j=1;
    int cnt = 1;
    int res = 0;

    while(cnt != k){
        if(a[i] < b[j]){
            ++cnt;
            res = a[i];
            ++i;
        }
        else{
            ++cnt;
            res = b[j];
            ++j;
        }
    }

    cout << res; 
}


void solve() {
    cin >> m >> n >> k;
    --k;

    for(int i=0; i<m; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
        cin >> b[i];
    merge();
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