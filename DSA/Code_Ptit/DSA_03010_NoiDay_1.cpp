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

        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            pq.push(x);
        }

        ll ans = 0;
        while(pq.size() > 1){
            ll num1 = pq.top(); pq.pop();
            ll num2 = pq.top(); pq.pop();

            ll sum = num1 + num2;
            ans += sum;
            pq.push(sum);
        }

        cout << ans << endl;
    }

    return 0;
}
