#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

/* Ý tưởng:

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
        int n;
        cin >> n;

        int a[n];
        for(int &x : a)
            cin >> x;

        sort(a,a+n);
        ll num1 = 0, num2 = 0;
        for(int i=0; i<n; i++){
            if(i%2==0)
                num1 = num1 * 10 + a[i];
            else
                num2 = num2 * 10 + a[i];
        }

        cout << num1 + num2 << endl;
    }


    return 0;
}
