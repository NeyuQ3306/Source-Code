#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: 

*/


// int n,k,X[100];
// vector<string> v(100);

// // int cnt = 0;

// // bool check(int n){
// //     for(int i=2; i<=sqrt(n); i++)
// //         if(n%i == 0)
// //             return false;

// //     return n>1;
// // }

// void inkq(){
//     for(int i=1; i<=k; i++){
//         cout << v[X[i]] << ' ';
//     }

//     cout << endl;
// }

// void Try(int i){
//     for(int j = X[i-1]+1; j <= n-k+i; j++){
//         X[i] = j;

//         if(i == k){
//             inkq();
//         }

//         else{
//             Try(i+1);
//         }
//     }
// }

int n;
int a[100][100];
vector<string> steps;
string s = "";

void nhap(){
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> a[i][j];
}

void Try(int i, int j){
    if(i==n && j==n){
        steps.push_back(s);
        return;
    }

    if(i+1 <=n && a[i+1][j] == 1){
        s += "D";
        Try(i+1,j);
        s.pop_back();
    }

    if(j+1 <= n && a[i][j+1] == 1){
        s += "R";
        Try(i,j+1);
        s.pop_back();
    }
}

void solve(){
    memset(a,0,sizeof(a));
    steps.clear();
    s.clear();

    nhap();
    Try(1,1);

    if(steps.empty() || a[1][1] == 0)
        cout << "-1" << endl;
    else{
        for(int i=0; i<steps.size(); i++)
            cout << steps[i] << " ";

        cout << endl;
    }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}