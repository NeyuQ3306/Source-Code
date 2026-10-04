#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: 

*/



void solve() {
    int t;
    cin >> t;

    while(t--){
        int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];


    vector<vector<int>> steps;


    for(int i=0; i<n-1; i++){
        bool ok = false;
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j+1], a[j]);
                ok = true;
            }
        }

        if(ok)
            steps.push_back(a);
        else
            break;
    }

    for(int i = steps.size() - 1; i >= 0; i--){
        cout << "Buoc " << i + 1 << ": ";
        for(int x : steps[i]) cout << x << ' ';
        cout << '\n';
    }
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