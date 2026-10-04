#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
bool check_final = false;
ll a[15];

/* Ý tưởng:

*/

void ktao(){
    for(int i=1; i<=n; i++){
        a[i] = 0;
    }
}

bool check(){
    int l = 1, r = n;
    while(l<=r){
        if(a[l] != a[r])
            return false;

        ++l, --r;
    }
    return true;
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

    cin >> n;
    ktao();

    while(check_final == false){
        if(check()){
            for(int i=1; i<=n; i++)
                cout << a[i] << ' ';

            cout << endl;
        }

        sinh();
    }

    return 0;
}