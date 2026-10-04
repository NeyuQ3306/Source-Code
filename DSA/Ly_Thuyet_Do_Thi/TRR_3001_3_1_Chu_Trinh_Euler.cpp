#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;


/* Ý tưởng:

*/

const long long mod = 1e9 + 7;
int n,m,u;
vector<set<int>> adj;
vector<bool> vis;
vector<int> ideg;
vector<int> odeg;
vector<int> deg;
vector<int> path;
vector<vector<int>> ke;
vector<vector<int>> lt;
vector<vector<int>> ts;
set<pair<int,int>> edge;
vector<pair<int,pair<int,int>>> canh;
vector<vector<int>> CC;
vector<int> EC;
vector<int> tmp;

void dfs(int u){
    vis[u] = true;

    for(int x : adj[u]){
        if(!vis[x])
            dfs(x);
    }
}


void solve(){
    int x;
    cin >> x;

    if(x == 1){
        cin >> n;
        adj.assign(n+1, set<int>());
        deg.assign(n+1,0);
        vis.assign(n+1,false);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int x;
                cin >> x;

                if(x){
                    adj[i].insert(j);
                    deg[i]++;
                }
            }
        }

        int start = 1;
        for(int i=1; i<=n; i++){
            if(deg[i] != 0){
                start = i;
                break;
            }
        }

        dfs(start);
        bool lt = true;

        for(int i=1; i<=n; i++){
            if(!vis[i]){
                lt = false;
                break;
            }
        }

        int bc = 0;
        for(int i=1; i<=n; i++){
            if(deg[i] % 2 == 0)
                ++bc;
        }

        if(lt && bc == n) cout << 1 << endl;
        else if(lt && (n-bc <= 2)) cout << 2 << endl;
        else cout << 0 << endl;
    }

    else{
        cin >> n >> u;
        adj.assign(n+1, set<int>());
        EC.clear();

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int x;
                cin >> x;

                if(x){
                    adj[i].insert(j);
                }
            }
        }

        stack<int> st;
        st.push(u);

        while(!st.empty()){
            int v = st.top();
            // cout << v << endl;

            if(adj[v].size() != 0){
                int x = *adj[v].begin();
                st.push(x);

                adj[v].erase(x);
                adj[x].erase(v);
            }

            else{
                st.pop();
                EC.push_back(v);
            }
        }

        reverse(EC.begin(), EC.end());
        for(int x : EC)
            cout << x << " ";

        cout << endl;
    }
}


int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("CT.INP","r",stdin);
    // freopen("CT.OUT","w",stdout);
    // // #else
    // // freopen("CK.INP","r",stdin);
    // // freopen("CK.OUT","w",stdout);
    // #endif

    // if(fopen("CT.INP", "r")){
    //     freopen("CT.INP","r",stdin);
    //     freopen("CT.OUT","w",stdout);
    // }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}