#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    int n;
    cin >> n;

    vll a(3*n);
    for(int i=0; i<3*n; i++) cin >> a[i];
    vll l(3*n), r(3*n);
    priority_queue<ll,vll,greater<ll>> q;
    ll sum = 0;

    for(int i=0; i<2*n; i++){
        q.push(a[i]);
        sum += a[i];

        if(q.size() > n){
            sum -= q.top();
            q.pop();
        }

        if(q.size() == n) l[i] = sum;
    }

    priority_queue<ll> q1;
    sum = 0;
    for(int i=3*n -1; i>=n; i--){
        q1.push(a[i]);
        sum += a[i];

        if(q1.size() > n){
            sum -= q1.top();
            q1.pop();
        }

        if(q1.size() == n) r[i] = sum;
    }

    ll ans = -1e18;
    for(int i=n-1; i<2*n; i++) ans = max(ans, l[i] - r[i+1]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
              
    while(t--){
       solve(); 
    }
    return 0;
}