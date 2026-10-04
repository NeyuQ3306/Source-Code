#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: 

*/



void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    int tmp = a[0];

    vector<vector<int>> steps;


    for(int i=1; i<n; i++){
        int pos = i-1, val = a[i];
        while(pos >= 0 && a[pos] > val){
            a[pos+1] = a[pos];
            --pos;
        }

        a[pos+1] = val;
        steps.push_back(vector<int>(a.begin(), a.begin() + i + 1));
    }

    for(int i = steps.size() - 1; i >= 0; i--){
        cout << "Buoc " << i + 1 << ": ";
        for(int x : steps[i]) cout << x << ' ';
        cout << '\n';
    }

    cout << "Buoc 0: " << tmp << endl;
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