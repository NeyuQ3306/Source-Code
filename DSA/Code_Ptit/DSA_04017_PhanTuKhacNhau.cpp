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

void twopointer(){
    int i=0, j=0;
    int res = 0;

    while(i<n  && j <n-1){
        if(a[i] != b[j]){
            res = i+1;
            break;
        }

        else
            ++i,++j;
    }

    cout << res;
}


void solve() {
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n-1; i++)
        cin >> b[i];
    twopointer();
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