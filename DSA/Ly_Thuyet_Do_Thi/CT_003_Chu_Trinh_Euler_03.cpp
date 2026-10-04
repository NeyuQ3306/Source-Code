#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;


/* Ý tưởng: Chú ý điều kiện nửa Euler là số bậc có bán bậc vào và bán bậc ra chênh nhau
1 phải = 2, <= 2 sẽ sai
- Ko đọc file
- Đọc input thông qua ma trận kề r mới chuyển qua danh sách kề trực tiếp từ ds cạnh bị
rte (ko hiểu sao)

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
        ideg.assign(n+1,0);
        odeg.assign(n+1,0);
        vis.assign(n+1,false);
        adjs.assign(n+1,set<int>());
        ke.assign(n+1,vector<int>(n+1, 0));

        for(int i=1; i<=n; i++){
            int sz;
            cin >> sz;

            for(int j=0; j<sz; j++){
                int y;
                cin >> y;

                ke[i][y] = 1;
            }
        }

        // xu li deg-, deg+
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(ke[i][j]){
                    odeg[i]++;
                    ideg[j]++;

                    adjs[i].insert(j);
                    adjs[j].insert(i);
                }
            }
        }

        // xu li lien thong yeu: G vo huong nen lien thong
        dfs(1);
        bool lt = true;
        for(int i=1; i<=n; i++){
            if(!vis[i] && odeg[i] > 0 && ideg[i] > 0){
                lt = false;
                break;
            }
        }


        bool dk1 = true; // deg- = deg+ voi moi v
        for(int i=1; i<=n; i++){
            if(odeg[i] != ideg[i]){
                dk1 = false;
                break;
            }
        }

        int dk2 = 0; // so dinh co |deg+ - deg- | == 1 ko vuot qua 2
        for(int i=1; i<=n; i++){

            if(abs(ideg[i] - odeg[i]) == 1)
                ++dk2;
        }


        if(lt && dk1) cout << 1 << endl;
        else if(lt && dk2 == 2) cout << 2 << endl;
        else cout << 0 << endl;

    }

    else{
        cin >> n >> u;
        adjs.assign(n+1,set<int>());
        EC.clear();
        ke.assign(n+1,vector<int>(n+1, 0));

        for(int i=1; i<=n; i++){
            int sz;
            cin >> sz;

            for(int j=0; j<sz; j++){
                int y;
                cin >> y;

                ke[i][y] = 1;
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(ke[i][j]){
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