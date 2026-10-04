#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 105;
ll n, m, cnt, k;
ll a[MAXN][MAXN], b[MAXN], c[MAXN], X[MAXN];

/* Ý tưởng: Thao tác merge ta có thể đếm cặp nghịch thế của 2 dãy tăng dần

*/

ll Merge(ll a[], ll l, ll m, ll r){
    vector<ll> x(a+l, a+m+1);
    vector<ll> y(a+m+1, a+r+1);

    // Mỗi khi trộn 2 đoạn tăng dần ta đếm số cặp nghịch thế
    ll ans = 0;
    ll i=0, j=0;
    while(i < x.size() && j < y.size()){
        // đúng vị trí i<j và x[i] < y[j]
        if(x[i] <= y[j]){
            a[l++] = x[i++];
        }

        // sai vị trí thì từ phần tử x[i] cho tới cuối mảng x đều tạo với y[j] cặp nghịch thế
        else{
            ans += x.size() - i;
            a[l++] = y[j++];
        }
    }

    while(i < x.size()){
        a[l++] = x[i++];
    }
    while(j < y.size()){
        a[l++] = y[j++];
    }

    return ans;
}

ll MergeSort(ll a[], ll l, ll r){
    ll dem = 0;
    if(l<r){
        ll m = (r+l)/2;
        dem += MergeSort(a,l,m);
        dem += MergeSort(a,m+1,r);
        dem += Merge(a,l,m,r);
    }
    return dem;
}

void solve() {
    cin >> n;
    ll a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    ll ans = MergeSort(a,0,n-1);
    cout << ans << endl;
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