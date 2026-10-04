#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
ll n, m, cnt, k;
ll a[MAXN], b[MAXN];
vector<string>res;
bool check_final = false;

/* Ý tưởng:
*/

ll Fibo[100];
void sinh(){
    Fibo[1] = 1;
    Fibo[2] = 1;

    for(int i=3; i<=93; i++)
        Fibo[i] = Fibo[i-2] + Fibo[i-1];
}

void FindFibo(int n, ll k){
    if(n==1){
        cout << '0';
        return;
    }

    if(n==2){
        cout << '1';
        return;
    }

    else{
        if(k <= Fibo[n-2])
            FindFibo(n-2,k);
        else
            FindFibo(n-1, k-Fibo[n-2]);
    }
}


void solve() {
    cin >> n >> k;
    FindFibo(n,k);
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

    sinh();
    while(t--){
        solve();
    }

    return 0;
}