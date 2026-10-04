#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MAXN = 1e7;

/* Ý tưởng: 

*/

int n, k, a[100], final;
void ktao(){
    for(int i=1; i<=n; i++){
        a[i] = i;
    }
}

// bool check(){
//    

//     return true;
// }

void sinh(){
    int i = n-1;
    while(i >= 1 && a[i] > a[i+1])
        --i;

    if(i==0)
        final = 1;

    else{
        int j=n;
        while(a[i] > a[j])
            --j;

        swap(a[j], a[i]);
        reverse(a+i+1, a+n+1);
    }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int b[n+1];

    for(int i=1; i<=n; i++)
        cin >> b[i];

    sort(b+1,b+n+1);

    ktao();
    while(!final){
        for(int i=1; i<=n; i++)
            cout << b[a[i]] << ' ';

        cout << endl;
        sinh();
    }
    
    
    return 0;
}