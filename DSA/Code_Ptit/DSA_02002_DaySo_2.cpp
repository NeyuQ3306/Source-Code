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

vector<int> a, b;
int n;
vector<string> steps;


void nhap(){
    cin >> n;

    a.resize(n);

    for(int i=0; i<n; i++)
        cin >> a[i];
}

void Try(int i){
    if(i==1)
        return;

    else{
        b.clear();
        for(int i=0; i<a.size()-1; i++)
            b.push_back(a[i] + a[i+1]);

        string tmp = "[";
        for(int i=0; i<b.size(); i++){
            if(i != b.size()-1)
                tmp += to_string(b[i]) + " ";
            else
                tmp += to_string(b[i]) + "]";
        }

        steps.push_back(tmp);
        a = b;
        Try(i-1);
    }
}

void solve(){
    steps.clear();
    nhap();

    string tmp = "[";
    for(int i=0; i<n; i++){
        if(i != n-1)
            tmp += to_string(a[i]) + " ";
        else
            tmp += to_string(a[i]) + "]";
    }

    steps.push_back(tmp);

    Try(n);

    for(int i=steps.size()-1; i>=0; i--)
        cout << steps[i] << " ";

    cout << endl;
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