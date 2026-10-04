#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: 

*/


int n,k,X[100], a[100];
vector<vector<int>> res;


void luukq(){
    vector<int> tmp;
    ll sum = 0;
    for(int i=1; i<=n; i++){
        if(X[i]){
            sum += a[i];
            tmp.push_back(a[i]);
        }
    }

    if(sum == k)
        res.push_back(tmp);
}

void Try(int i){
    for(int j=0; j<=1; j++){
        X[i] = j;

        if(i == n)
            luukq();
        else
            Try(i+1);
    }
}

void solve(){
    res.clear();
    memset(a,0,sizeof(a));

    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    sort(a+1,a+n+1);
    Try(1);

    if(res.empty())
        cout << "-1" << endl;

    else{
        sort(res.begin(), res.end());
        for(int i=0; i<res.size(); i++){
            cout << "[";
            for(int j=0; j<res[i].size(); j++){
                if(j != res[i].size()-1)
                    cout << res[i][j] << " ";
                else 
                    cout << res[i][j] << "]";
            }

            cout << " ";
        }
    }

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