#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, k, ans;
bool check_final = false;
ll a[15], b[MAXN];

/* Ý tưởng:

*/

void ktao(){
    for(int i=1; i<=n; i++){
        a[i] = 0;
    }
}

bool check(){
    ll sum = 0;
    for(int i=1; i<=n; i++){
        sum += a[i] * b[i];
    }

    return sum == k;
}

void sinh(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        --i;
    }

    if(i==0)
        check_final = true;

    else
        a[i] = 1;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> b[i];

    ktao();

    while(check_final == false){
        if(check()){
            for(int i=1; i<=n; i++){
                if(a[i])
                    cout << b[i] << ' ';
            }    

            ++ans;
            cout << endl;
        }

        sinh();
    }

    cout << ans << endl;

    return 0;
}