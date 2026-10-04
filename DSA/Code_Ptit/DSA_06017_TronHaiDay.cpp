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
    int res[n+m+1];
    sort(a,a+n);
    sort(b,b+m);

    int i=0, j=0, idx=0;
    while(i<n && j<m){
        if(a[i] < b[j]){
            res[idx++] = a[i++];
        }
        else{
            res[idx++] = b[j++];
        }
    }

    while(i<n)
        res[idx++] = a[i++];
    while(j<m)
        res[idx++] = b[j++];


    for(int i=0; i<idx; i++)
        cout << res[i] << " ";
}

void solve() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int j=0; j<m; j++)
        cin >> b[j];

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