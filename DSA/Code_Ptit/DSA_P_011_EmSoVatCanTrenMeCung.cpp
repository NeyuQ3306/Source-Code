#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;


int n,m;
char a[1005][1005];

/* Ý tưởng:
*/

int di[4] = {0,-1,0,1};
int dj[4] = {-1,0,1,0};

void loang(int i, int j){
    a[i][j] = '.';

    for(int k=0; k<4; k++){
        int i1 = i + di[k];
        int j1 = j + dj[k];

        if(i1>0 && i1<=n && j1>0 && j1<=m && a[i1][j1] == '#')
            loang(i1,j1);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
            cin >> a[i][j];
    }

    ll ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] == '#'){
                ++ans;
                loang(i,j);
            }
        }
    }

    cout << ans << endl;
    return 0;
}