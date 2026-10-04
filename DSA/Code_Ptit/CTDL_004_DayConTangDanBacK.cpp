#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MAXN = 1e7;

/* Ý tưởng: 

*/

int n, k, a[105], b[105], final;
void ktao(){
    for(int i=1; i<=k; i++){
        a[i] = i;
    }
}

bool check(){
    for(int i=1; i<k; i++)
        if(b[a[i]] > b[a[i+1]])
            return false;

    return true;
}

void sinh(){
    int i=k; 
    while(i>=1 && a[i] == n-k+i){
        --i;
    }

    if(i==0)
        final = 1;
    else{
        a[i]++;
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

    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> b[i];


    int cnt = 0;
    final = 0;
    ktao();
    while(!final){
        if(check()){
            ++cnt;
        }

        sinh();
    }

    cout << cnt;
    
    return 0;
}