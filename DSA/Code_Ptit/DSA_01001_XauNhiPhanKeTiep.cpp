#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
bool check_final = false;
int a[MAXN];


/* Ý tưởng:
*/
void ktao(){
    
}

void sinh(){
    
}

void solve(string &s){
    int i = s.size() - 1;
    while(i >= 0 && s[i] == '1'){
        s[i] = '0';
        --i;
    }

    if(i >= 0)
        s[i] = '1';
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
        string s;
        cin >> s;

        solve(s);
        cout << s << endl;
    }
    return 0;
}