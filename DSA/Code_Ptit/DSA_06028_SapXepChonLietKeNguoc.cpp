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

    vector<vector<int>> steps;
    for(int i=0; i<n-1; i++){
        int min_pos = i;
        for(int j=i+1; j<n; j++){
            if(a[j] < a[min_pos])
                min_pos = j;
        }

        swap(a[min_pos], a[i]);
        steps.push_back(a);
    }

    for(int i=steps.size() - 1; i>=0; i--){
        cout << "Buoc " << i+1 << ": ";
        for(int x : steps[i])
            cout << x << ' ';

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