#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MAXN = 1e7;

/* Ý tưởng: 

*/

int n, k, a[50], b[50], final;
void ktao(){
    for(int i=1; i<=k; i++){
        a[i] = i;
    }
}

// bool check(){
    
// }

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

    int t;
    cin >> t;

    while(t--){
        final = 0;
        cin >> n >> k;
        for(int i=1; i<=k; i++)
            cin >> a[i];

        set<int> se;
        for(int i=1; i<=k; i++)
            se.insert(a[i]);

        int tmp = se.size();
        sinh();

        int cnt = 0;
        if(final)
            cout << k << endl;
        else{
            for(int i=1; i<=k; i++)
                se.insert(a[i]);

            cout << se.size() - tmp << endl;
        }

        


    }
    
    return 0;
}