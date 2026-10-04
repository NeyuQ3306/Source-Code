#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MAXN = 1e7;

/* Ý tưởng: 

*/

int n, w, a[100], b[100], final;
void ktao(){
    for(int i=1; i<=n; i++){
        a[i] = 0;
    }
}

// bool check(){
//    

//     return true;
// }

void sinh(){
    int i=n; 
    while(i>=1 && a[i] == 1){
        a[i] = 0;
        --i;
    }

    if(i==0)
        final = 1;
    else
        a[i] = 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;

    int c[n+1], d[n+1];
    for(int i=1; i<=n; i++)
        cin >> c[i];

    for(int i=1; i<=n; i++)
        cin >> d[i];

    ktao();
    ll fopt = 0;
    int xopt[n+1];

    while(!final){
        ll weight = 0;
        for(int i=1; i<=n; i++)
            weight += a[i] * d[i];

        if(weight <= w){
            ll sum = 0;
            for(int i=1; i<=n; i++)
                sum += a[i] * c[i]; // f(X)

            if(sum > fopt){
                copy(a+1, a+n+1, xopt+1);
                fopt = sum;
            }

        }

        sinh();
    }

    cout << fopt << endl;
    for(int i=1; i<=n; i++)
        cout << xopt[i] << ' ';
    
    return 0;
}