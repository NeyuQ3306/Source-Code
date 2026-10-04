#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;


/* Ý tưởng: Chú ý điều kiện G có hướng là đồ thị nửa Euler khi có 2 đỉnh có chênh lệch
ideg odeg = 1 thì phải là 
if(ideg[i] - odeg[i] == 1)
    ++t1;
if(odeg[i] - ideg[i] == 1)
    ++t2;

- Nếu chỉ tính số lượng đỉnh chênh lệch == 2 sẽ sai 

*/

const long long mod = 1e9 + 7;
int n,m,u;
vector<set<int>> adjs;
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

    for(int x : adjs[u]){
        if(!vis[x])
            dfs(x);
    }
}

void bfs(int u){
    queue<int> q;
    vis[u] = true;
    q.push(u);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int x : adjs[v]){
            if(!vis[x]){
                vis[x] = true;
                q.push(x);
            }
        }
    }
}


void solve(){
    int x;
    cin >> x;

    if(x == 1){
        cin >> n;
        adjs.assign(n+1,set<int>());
        ideg.assign(n+1, 0);
        odeg.assign(n+1, 0);
        vis.assign(n+1, false);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int x;
                cin >> x;

                if(x){
                    odeg[i]++;
                    ideg[j]++;

                    adjs[i].insert(j);
                    adjs[j].insert(i);
                }
            }
        }


        dfs(1);
        bool lt = true;
        for(int i=1; i<=n; i++){
            if(!vis[i] && odeg[i] > 0 && ideg[i] > 0){
                lt = false;
                break;
            }
        }

        bool dk1 = true;
        for(int i=1; i<=n; i++){
            if(ideg[i] != odeg[i]){
                dk1 = false;
                break;
            }
        }

        int t1 = 0, t2 = 0;
        for(int i=1; i<=n; i++){
            if(ideg[i] - odeg[i] == 1)
                ++t1;
            if(odeg[i] - ideg[i] == 1)
                ++t2;
        }


        if(lt && dk1) cout << 1 << endl;
        else if(lt && t1 == 1 && t2 == 1) cout << 2 << endl;
        else cout << 0 << endl;
    }

    else{
        cin >> n >> u;
        adjs.assign(n+1,set<int>());
        EC.clear();

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int x;
                cin >> x;

                if(x){
                    adjs[i].insert(j);
                }
            }
        }

        stack<int> st;
        st.push(u);

        while(!st.empty()){
            int v = st.top();

            if(adjs[v].size() != 0){
                int x = *adjs[v].begin();
                st.push(x);

                adjs[v].erase(x);
            }

            else{
                EC.push_back(v);
                st.pop();
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