#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define sz size
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int si,sj,ei,ej;
int a[10][10], vis[10][10];

int di[8] = {-2,-2,-1,1,2,2,1,-1};
int dj[8] = {-1,1,2,2,1,-1,-2,-2};

void bfs(){
    queue<pair<pair<int,int>, int>> q;
    memset(vis,0,sizeof(vis));
    q.push({{si,sj}, 0});
    vis[si][sj] = 1;

    while(!q.empty()){
        pair<pair<int,int>, int> t = q.front();
        q.pop();

        int i = t.fi.fi, j = t.fi.se, step = t.se;
        if(i == ei && j == ej){
            cout << step << endl;
            return;
        }

        for(int k=0; k<8; k++){
            int i1 = i + di[k];
            int j1 = j + dj[k];

            if(i1 <= 8 && i1 >= 1 && j1 >= 1 && j1 <= 8 && vis[i1][j1] == 0){
                vis[i1][j1] = 1;
                q.push({{i1,j1}, step + 1});
            }
        }
    }
}


void solve() {
    char x,y,z,t;
    cin >> x >> y >> z >> t;

    sj = x - 'a' + 1;
    si = 8 - (y - '0') + 1; 
    ej = z - 'a' + 1;
    ei = 8 - (t - '0') + 1;

    // cout << si << " " << sj << " " << ei << " " << ej << endl;

    bfs();
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