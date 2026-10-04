#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

/* Ý tưởng: Ta tham lam theo tư tưởng
Muốn không có 2 ký tự giống nhau đứng cạnh nhau
⇒ ký tự xuất hiện nhiều nhất không được quá nhiều.
- max_fre <= (n+1)/2
*/



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
        string s;
        cin >> s;

        map<char,ll> mp;
        for(char c : s)
            mp[c]++;

        ll max_fre = 0;
        for(auto x : mp)
            max_fre = max(max_fre, x.second);

        if(max_fre <= (s.size()+1)/2)
            cout << "1" << endl;
        else
            cout << "-1" << endl;
    }

    return 0;
}
