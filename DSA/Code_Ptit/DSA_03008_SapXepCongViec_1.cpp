#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

/* Ý tưởng:

*/

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
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
        int n;
        cin >> n;

        pair<int,int> a[n];
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            a[i].first = x;
        }

        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            a[i].second = x;
        }

        sort(a,a+n,cmp);
        // for(auto x : a)
        //     cout << x.first << " " << x.second << endl;

        ll cnt = 1;
        int end = a[0].second;
        for(int i=1; i<n; i++){
            if(a[i].first >= end){
                ++cnt;
                end = a[i].second;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
