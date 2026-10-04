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

    for(int i=0; i<n-1; i++){
        int min_pos = i;
        bool ok = false;
        for(int j=i+1; j<n; j++){
            if(a[j] < a[min_pos]){
                min_pos = j;
                ok = true;
            }
        }

        swap(a[min_pos], a[i]);
        cout << "Buoc " <<  i+1 << ": ";
        for(int k=0; k<n; k++)
            cout << a[k] <<  ' ';

        cout << endl;

        if(ok == false)
            break;

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