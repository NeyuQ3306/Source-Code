#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6;
ll n, m, k;
ll a[MAXN];


/* Ý tưởng: 

*/



void solve() {
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> a[i];

    cout << "Buoc 0: " << a[0] << endl;

    for(int i=1; i<n; i++){
        int pos = i-1, value = a[i];
        while(pos >= 0 && a[pos] > value){
            a[pos+1] = a[pos];
            --pos; 
        }

        a[pos + 1] = value;

        cout << "Buoc " << i<< ": ";
        for(int k=0; k<=i; k++)
            cout << a[k] << ' ';

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