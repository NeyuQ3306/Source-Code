#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    int N;
    cin >> N;

    queue<pii> qu;
    set<int> set;
    
    set.insert(N);
    qu.push({N,0});

    while(!qu.empty()){
        pii top = qu.front();
        qu.pop();

        if(top.fi == 1){
            cout << top.se << endl;
            break;
        }

        if(set.find(top.fi - 1) == set.end() && top.fi > 1){
            qu.push({top.fi-1, top.se+1});
            set.insert(top.fi-1);
        }

        int n = top.fi;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0){
                int u = i, v = n/i;
                int tmp = max(u,v);

                if(set.find(tmp) == set.end()){
                    qu.push({tmp, top.se+1});
                    set.insert(tmp);
                }
            }
        }


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