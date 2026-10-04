#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6;
ll n, m, k;
ll a[MAXN], b[MAXN];

/* Ý tưởng: Vì dữ liệu bài này là n < 10^3 nên có thể dùng SelectionSort
- Mỗi lần đưa ptu nhỏ nhất lên đầu thì số swap sẽ tối thiểu
- Với dữ liệu lớn hơn ta phải dùng chu trình hoán vị sẽ cho đpt O(nlogn)

*/



void solve() {
    int t;
    cin >> t;

    while(t--){
        cin >> n >> m;
        set<int> se;
        map<int,int> mp;

        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            se.insert(x);

            mp[x] = 1;
        }

        for(int i=0; i<m; i++){
            int y;
            cin >> y;
            se.insert(y);
            if(mp[y])
                mp[y] = 2;
        }

        for(auto x : se)
            cout << x << ' ';

        cout << endl;

        for(auto x : mp){
            if(x.second == 2)
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