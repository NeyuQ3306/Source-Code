#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m, cnt, k;
ll aa[MAXN][MAXN], a[MAXN];
vector<string>res;
bool check_final = false;

/* Ý tưởng: 
*/

void ktao(){
    cnt = 1;
    a[1] = n;
}

void sinh(){
    int i = cnt;
    while(i>=1 && a[i] == 1)
        --i;

    if(i==0)
        check_final = true;
    else{
        --a[i];
        int d = cnt - i + 1;
        cnt = i;

        int q = d/a[i], r = d%a[i];
        if(q){
            for(int j=1; j<=q; j++){
                ++cnt;
                a[cnt] = a[i];
            }
        }

        if(r){
            ++cnt;
            a[cnt] = r;
        }
    }
}



void solve() {
    check_final = false;
    cnt = 0;
    memset(a,0,sizeof(a));
    res.clear();

    cin >> n;
    ktao();

    while(!check_final){
        string s = "(";
        for(int i=1; i<=cnt; i++){
            if(i != cnt)
                s += to_string(a[i]) + " ";
            else
                s += to_string(a[i]) + ")";
        }

        res.push_back(s);
        sinh();
    }

    cout << res.size() << endl;
    for(int i=0; i<res.size(); i++)
        cout << res[i] << " ";

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