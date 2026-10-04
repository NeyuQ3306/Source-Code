#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define sz size
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    ll n;
    cin >> n;

    queue<ll> q;
    q.push(1);

    while(1){
        ll u = q.front();
        q.pop();

        if(u % n == 0){
            cout << u << endl;
            return;
        }

        q.push(u*10);
        q.push(u*10 + 1);
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