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

set<ll> se;
void xuly(){
    queue<ll> q;
    for(int i=1; i<=5; i++){
        q.push(i);
        se.insert(i);
    }

    while(!q.empty()){
        ll t = q.front();
        q.pop();

        if(t > 1e6) break;
        set<int> dgit;
        int tmp = t;
        while(t){
            dgit.insert(t%10);
            t/=10;
        }

        for(int j=0; j<=5; j++){
            if(dgit.find(j) == dgit.end()){
                q.push(tmp*10 + j);
                se.insert(tmp*10 + j);
            }
        }
    }
}

void solve() {
    int l,r;
    cin >> l >> r;

    int cnt = 0;
    for(int i=l; i<=r; i++){
        if(se.find(i) != se.end()){
            // cout << i << " ";
            ++cnt;
        }
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    xuly();
              
    while(t--){
       solve(); 
    }
    return 0;
}