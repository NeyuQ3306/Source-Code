#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MAXN = 1e7;

/* Ý tưởng: 

*/

int n, k, a[100], final;
void ktao(){
    for(int i=1; i<=n; i++){
        a[i] = 0;
    }
}

bool check(){
    if(n < 6)
        return false;

    if(a[1] != 1 || a[n] != 0)
        return false;

    for(int i=1; i<n; i++){
        if(a[i] == 1 && a[i] == a[i+1])
            return false;
    }

    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(a[i] == 0)
            ++cnt;
        else
            cnt = 0;

        if(cnt > 3)
            return false;
    }

    return true;
}

void sinh(){
    int i = n;
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
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        cin >> n;
        final = 0;
        memset(a,0,sizeof(a));
        ktao();

        while(!final){
            if(check()){
                for(int i=1; i<=n; i++){
                    if(a[i])
                        cout << "8";
                    else
                        cout << "6";
                }

                cout << endl;
            }

            sinh();

    }
    
    return 0;
}