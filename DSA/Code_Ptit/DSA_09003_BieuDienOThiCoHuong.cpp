#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
// vector<vector<int>> adj(1001); // danh sach ke
vector<pair<int,int>> edge; // danh sach canh
// int a[1001][1001]; // ma tran ke

void solve() {
    cin >> n >> m;
    vector<vector<int>> adj(n+1); // danh sach ke

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    for(int i=1; i<=n; i++){
        cout << i << ": ";
        for(int x : adj[i]) cout << x << " ";
        cout << endl;
    }
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