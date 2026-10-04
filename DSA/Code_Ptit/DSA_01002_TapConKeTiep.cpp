#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MAXN = 1e7;

/* Ý tưởng: 

*/

int n,k, a[1005], final;
void ktao(){
    for(int i=1; i<=n; i++){
        a[i] = i;
    }
}

// bool check(){
    
// }

void sinh(){
    int i = k;
    while(i>=1 && a[i] == n-k+i)
        --i;

    if(i==0)
        final = 1;
    else{
        ++a[i];
        for(int j=i+1; j<=k; j++)
            a[j] = a[j-1] + 1;
    }
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
        final = 0;
        memset(a,0,sizeof(a));

        for(int i=1; i<=k; i++)
            cin >> a[i];

        sinh();
        if(final){
            ktao();
            for(int i=1; i<=k; i++)
                cout << a[i] << ' ';
        }

        else{
            for(int i=1; i<=k; i++)
                cout << a[i] << ' ';
        }

        cout << endl;


    }
    
    return 0;
}