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

string s,t;
set<string> se;

int nt[10005];
void sang(){
    memset(nt,1,sizeof(nt));
    nt[0] = nt[1] = 0;

    for(int i=2; i<=sqrt(10000); i++){
        if(nt[i]){
            for(int j=i*i; j<=10000; j+=i){
                nt[j] = 0;
            }
        }
    }
}

void bfs(){
    queue<pair<string,int>> q;
    q.push({s,0});
    se.insert(s);

    while(!q.empty()){
        auto top = q.front();
        q.pop();

        string u = top.fi;
        int step = top.se;
        if(u == t){
            cout << step << endl;
            return;
        }

        for(int i=0; i<4; i++){
            for(int j=0; j<=9; j++){
                string tmp = u;
                if(i==0 && j==0) continue;
                if(tmp[i] != j + '0'){
                    tmp[i] = j + '0';
                    if(nt[stoi(tmp)] && se.find(tmp) == se.end()){
                        q.push({tmp, step+1});
                        se.insert(tmp);
                    }
                }
            }
        }
    }
}

void solve() {
    cin >> s >> t;
    se.clear();
    bfs();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;

    sang();
              
    while(test--){
       solve(); 
    }
    return 0;
}