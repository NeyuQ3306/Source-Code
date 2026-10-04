#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: 

*/


int n,m,k,X[100], a[100], dp[100][100];
int cheoxuoi[100], cheonguoc[100], cot[100];
vector<vector<int>> res;
ll ans = 0;

void luukq(){
    vector<int> tmp;
    for(int i=1; i<=n; i++)
        if(X[i]) tmp.push_back(a[i]);

    if(tmp.size() <= 1)
        return;

    bool check = true;
    for(int i=0; i<tmp.size()-1; i++){
        if(tmp[i] > tmp[i+1]){
            check = false;
            break;
        }
    }

    if(check){
        res.push_back(tmp);
    }
}

void Try(int i){
    for(int j=0; j<=1; j++){
        X[i] = j;

        if(i==n)
            luukq();
        else
            Try(i+1);
    }
}

bool cmp(vector<int> a, vector<int> b){
    string tmp1 = "", tmp2 = "";
    for(int x : a)
        tmp1 += to_string(x) + " ";
    tmp1.pop_back();

    for(int x : b)
        tmp2 += to_string(x) + " ";
    tmp2.pop_back();
    
    return tmp1 < tmp2;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];


    Try(1);
    sort(res.begin(), res.end(), cmp);

    for(int i=0; i<res.size(); i++){
        for(int x : res[i])
            cout << x << " ";

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
    
    solve();
    return 0;
}