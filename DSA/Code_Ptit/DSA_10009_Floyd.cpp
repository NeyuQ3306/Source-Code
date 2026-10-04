#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int d[1005][1005];
int n,m;

void Floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) d[i][j] = 0;
            else d[i][j] = 1e9;
        }
    }

    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;

        d[x][y] = d[y][x] = z;
    }

    Floyd();
    int q;
    cin >> q;

    while(q--){
        int x,y;
        cin >> x >> y;

        cout << d[x][y] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
              
    while(t--){
       solve(); 
    }
    return 0;
}