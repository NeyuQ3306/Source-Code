#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,s,x[101],a[101];
vector<vector<int>> res;

void ql(int i, int bd, int sum){
    for(int j=bd; j<=n; j++){
        if(sum + a[j] <= s){
            x[i] = a[j];

            if(sum + a[j] == s){
                vector<int> tmp(x+1,x+i+1);
                res.push_back(tmp);
            }

            else ql(i+1,j,sum+a[j]);
        }
    }
}

void solve() {
    cin >> n >> s;
    memset(x,0,sizeof(x));
    memset(a,0,sizeof(a));
    res.clear();

    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);

    ql(1,1,0);
    if(res.size() == 0) cout << "-1\n";
    else{
        cout << res.size() << " ";
        for(auto x : res){
            cout << "{";
            for(int i=0; i<x.size(); i++){
                if(i != x.size()-1) cout << x[i] << ' ';
                else cout << x[i] << "} ";
            }
        }
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
              
    while(t--){
       solve(); 
    }
    return 0;
}