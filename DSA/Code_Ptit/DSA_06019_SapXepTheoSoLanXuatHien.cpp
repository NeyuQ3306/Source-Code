#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6;
ll n, m, k;
ll a[MAXN];


/* Ý tưởng: 

*/

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;

    else
        return a.second > b.second;
}


void solve() {
    int t;
    cin >> t;

    while(t--){
        cin >> n;
        map<int,int> mp;

        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            mp[x]++;
        }

        vector<pair<int,int>> v;
        for(auto x : mp){
            v.push_back({x.first, x.second});
        }

        sort(v.begin(), v.end(), cmp);
        for(auto x : v){
            for(int i=1; i<=x.second; i++)
                cout << x.first << ' ';
        }


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