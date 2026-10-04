#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e3;
ll n, m, k;
ll a[MAXN];


/* Ý tưởng: 

*/


void solve() {
    int t;
    cin >> t;

    while(t--){
        int x;
        cin >> n >> x;

        map<int,int> mp;
        for(int i=0; i<n; i++){
            int tmp;
            cin >> tmp;

            mp[tmp]++;
        }

        if(mp.find(x) == mp.end())
            cout << "-1";

        else 
            cout << mp[x];


        cout << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}