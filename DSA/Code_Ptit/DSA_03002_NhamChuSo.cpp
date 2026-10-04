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

    string a,b;
    cin >> a >> b;

    for(int i=0; i<a.size(); i++){
        if(a[i] == '6')
            a[i] = '5';

        if(b[i] == '6')
            b[i] = '5';
    }

    ll num1 = stoll(a), num2 = stoll(b);
    cout << num1 + num2 << " ";

    for(int i=0; i<a.size(); i++){
        if(a[i] == '5')
            a[i] = '6';

        if(b[i] == '5')
            b[i] = '6';
    }

    ll num3 = stoll(a), num4 = stoll(b);
    cout << num3 + num4 << endl;


    return 0;
}
