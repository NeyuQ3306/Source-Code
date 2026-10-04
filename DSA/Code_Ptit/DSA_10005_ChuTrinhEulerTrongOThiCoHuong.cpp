#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/
int n,m;
vector<pair<int,int>> degree(1001);

void solve() {
    cin >> n >> m;
    degree.assign(n+1,{});

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        // first: ban bac ra, second: ban bac vao
        degree[x].first++;
        degree[y].second++;
    }

    // De bai da cho do thi G co huong lien thong yeu chi ktra deg+, deg-
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(degree[i].first != degree[i].second) ++cnt;
    }

    if(cnt == 0) cout << "1" << endl; // co chu trinh Euler do moi v thuoc V co deg+ = deg-
    else cout << "0" << endl;
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