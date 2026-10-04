#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];
vector<string>res;
map<pair<int,int>,char> mp;
string s;

/* Ý tưởng: Di chuyển trong mê cung 2
- Ta dùng map để lưu các lượng di chuyển tương ứng với chữ cái D,L,R,U 
- Các lượng di chuyển:
Down: i=1, j=0;
Left: i=0, j=-1;
Right: i=0, j=1;
Up: i=-1, j=0;
*/


void sinh_map(){
   mp[{1,0}] = 'D';
   mp[{0,-1}] = 'L';
   mp[{0,1}] = 'R';
   mp[{-1,0}] = 'U';
}

void loang(int i, int j){
    if(i==1 && j==1)
        a[1][1] = 0;

    if(i==n && j==n){
        res.push_back(s);
        return;
    }

    for(auto x : mp){
        int i1 = i + x.first.first;
        int j1 = j + x.first.second;

        if(i1 >= 1 && i1 <=n && j1 >= 1 && j1 <= n && a[i1][j1] == 1){
            a[i1][j1] = 0;
            s += x.second;
            loang(i1,j1);
            s.pop_back();
            a[i1][j1] = 1;
        }

    }
}

void solve() {
    s.clear();
    res.clear();
    memset(a,0,sizeof(a));
    cin >> n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> a[i][j];

    if(a[1][1] == 0){
        cout << "-1" << endl;
        return;
    }

    loang(1,1);
    if(res.empty())
        cout << "-1" << endl;
    else{
        sort(res.begin(), res.end());
        for(int i=0; i<res.size(); i++)
            cout << res[i] << " ";
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

    sinh_map();

    while(t--){
        solve();
    }

    return 0;
}