#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MAXN = 1e7;

/* Ý tưởng: 

*/

int n, k, a[100], b[100], final;
void ktao(){
    for(int i=1; i<=k; i++){
        a[i] = i;
    }
}

// bool check(){
//    

//     return true;
// }

void sinh(){
    int i=k;
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

    int s;
    cin >> s >> k;

    set<int> se;
    for(int i=0; i<s; i++){
        int x;
        cin >> x;
        se.insert(x);
    }

    n = se.size();
    int idx = 1;
    for(auto x : se)
        b[idx++] = x;


    ktao();
    while(!final){
        for(int i=1; i<=k; i++)
            cout << b[a[i]] << ' ';

        cout << endl;
        sinh();
    }
    
    return 0;
}