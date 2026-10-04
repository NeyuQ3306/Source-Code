#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6;
ll n, m, k;
ll a[MAXN];


/* Ý tưởng: 

*/

int nt[MAXN];
void sang(){
    for(int i=0; i<MAXN; i++)
        nt[i] = 1;

    nt[0] = nt[1] = 0;
    for(int i=2; i<sqrt(MAXN); i++){
        if(nt[i]){
            for(int j=i*i; j<= MAXN; j+=i)
                nt[j] = 0;
        }
    }
}


void solve() {
    int t;
    cin >> t;

    sang();

    while(t--){
        cin >> n;

        bool check = true;
        for(int i=2; i<n; i++){
            if(nt[i] && nt[n-i]){
                check = false;
                cout << i << ' ' << n-i;
                break;
            }
        }


        if(check)
            cout << "-1";
        
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