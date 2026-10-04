#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
// #define sz size
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

set<int> se;
int X[15], a[100];
int n, sz;

void ql(int i){
    for(int j=0; j<sz; j++){
        X[i] = a[j];
        if(i == n){
            for(int k=1; k<=n; k++) cout << X[k];
            cout << endl;
        }

        else if(i < n) ql(i+1);
    }
}

void solve() {
    cin >> n;

    for(int i=0; i<3; i++){
        int x;
        cin >> x;

        se.insert(x);
    }

    sz = se.size();
    int idx = 0;
    for(auto x : se) a[idx++] = x; 
    ql(1);
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