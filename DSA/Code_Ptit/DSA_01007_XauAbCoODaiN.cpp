#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MAXN = 1e7;

/* Ý tưởng: 

*/

int n, a[15], check;
void ktao(){
    for(int i=1; i<=n; i++){
        a[i] = 0;
    }
}

void sinh(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        --i;
    }

    if(i==0)
        check = 1;

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

    int t;
    cin >> t;

    while(t--){
        cin >> n;
        check = 0;
        ktao();

        while(check == 0){
            for(int i=1; i<=n; i++){
                if(a[i])
                    cout << 'B';
                else
                    cout << 'A';
            }

            cout << ' ';
            sinh();
        }

        cout << endl;

    }
    
    return 0;
}