#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n, m, st;
vector<vector<pair<int,int>>> adj;


void Dijkstra(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> d(n+1,1e9);
    d[s] = 0;
    pq.push({0,s});

    while(!pq.empty()){
        pair<int,int> top = pq.top();
        pq.pop();

        int exp = top.first, u = top.second;
        if(exp > d[u]) continue;

        for(auto x : adj[u]){
            int v = x.first, w = x.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }

    for(int i=1; i<=n; i++) cout << d[i] << " ";
    cout << endl;
}

void solve() {
    cin >> n >> m >> st;
    adj.assign(n+1,{});

    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;

        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    Dijkstra(st);
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