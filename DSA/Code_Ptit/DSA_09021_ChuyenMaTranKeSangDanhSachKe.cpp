#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
// vector<vector<int>> adj(1001); // danh sach ke
// vector<pair<int,int>> edge; // danh sach canh
int a[1001][1001]; // ma tran ke

void solve() {
    cin >> n;
    vector<vector<int>> adj(n+1);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i][j]) adj[i].push_back(j);
        }
    }

    for(int i=1; i<=n; i++){
        for(int x : adj[i]) cout << x << " ";
        cout << endl;
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