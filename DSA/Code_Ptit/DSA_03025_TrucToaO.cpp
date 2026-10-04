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
    int n;
    cin >> n;

    pair<int,int> a[n];
    for(pair<int,int> &p : a) cin >> p.first >> p.second;

    sort(a,a+n, [](pair<int,int> a, pair<int,int> b){
        if(a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    });

    ll cnt = 1;
    ll end = a[0].second;

    for(int i=1; i<n; i++){
        if(a[i].first >= end){
            ++cnt;
            end = a[i].second;
        }
    }

    cout << cnt << endl;
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