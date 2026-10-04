#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MAXN = 1e7;

/* Ý tưởng: 

*/

int n,k, a[20], check;
void ktao(){
    for(int i=1; i<=n; i++){
        a[i] = 0;
    }
}

bool check_k(){
    int cnt = 0;
    for(int i=1; i<=n; i++)
        if(a[i])
            ++cnt;

    return cnt == k;
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
        cin >> n >> k;
        check = 0;
        ktao();

        while(check == 0){
            if(check_k()){
                for(int i=1; i<=n; i++)
                    cout << a[i];

                cout << endl;
            }
            sinh();
        }

    }
    
    return 0;
}