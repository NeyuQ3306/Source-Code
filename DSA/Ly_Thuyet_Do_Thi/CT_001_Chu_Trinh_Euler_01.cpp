#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

// ifstream fin("CT.INP");
// ofstream fout("CT.OUT");


int n,m,u;
vector<vector<int>> adj;
vector<set<int>> adjs;
vector<bool> vis;
vector<int> deg;
vector<int> path;


void dfs(int u){
    vis[u] = true;
    for(int x : adj[u]){
        if(!vis[x]) dfs(x);
    }
}

void solve1() {
    cin >> n >> m;
    adj.assign(n+1,{});
    vis.assign(n+1,false);
    deg.assign(n+1,0);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);

        deg[x]++;
        deg[y]++;
    }


    bool lt = true;
    int start = 1;
    for(int i=1;i<=n;i++){
        if(deg[i] > 0){
            start = i;
            break;
        }
    }
    dfs(start);

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            lt = false;
            break;
        }
    }

    int bc = 0, bl = 0;
    for(int i=1; i<=n; i++){
        if(deg[i] % 2 == 0) ++bc;
        else ++bl;
    }

    if(lt && bc == n) cout << "1" << endl;
    else if(lt && bl <= 2) cout << "2" << endl;
    else cout << "0" << endl;

}

void EC(int u){
    stack<int> st;
    st.push(u);

    while(!st.empty()){
        int top = st.top();
        if(adjs[top].size() != 0){
            int y = *adjs[top].begin();
            st.push(y);

            adjs[top].erase(y);
            adjs[y].erase(top);
        }

        else{
            st.pop();
            path.push_back(top);
        }
    }

    reverse(path.begin(), path.end());
    for(int x : path) cout << x << " ";
    cout << endl;
}

void solve2() {
    cin >> n >> m >> u;
    path.clear();
    adjs.assign(n+1,{});
    vis.assign(n+1,false);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        adjs[x].insert(y);
        adjs[y].insert(x);
    }

    EC(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    if(t == 1){
        solve1();
    }

    else if(t == 2){
        solve2();
    }
    
    return 0;
}