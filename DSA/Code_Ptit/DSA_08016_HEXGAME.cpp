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

/* Ý tưởng: TLE =))))
*/

string start;
string xoay_trai(string s){
    string res = s;
    res[0] = s[3];
    res[1] = s[0];
    res[5] = s[1];
    res[8] = s[5];
    res[7] = s[8];
    res[3] = s[7];

    return res;
}

string xoay_phai(string s){
    string res = s;
    res[1] = s[4];
    res[2] = s[1];
    res[6] = s[2];
    res[9] = s[6];
    res[8] = s[9];
    res[4] = s[8];

    return res;
}

unordered_set<string> se;
void bfs(){
    queue<pair<string,int>> q;
    q.push({start, 0});

    while(!q.empty()){
        auto top = q.front();
        q.pop();

        string s1 = top.fi;
        int step = top.se;

        if(s1 == "1238004765"){
            cout << step << endl;
            return;
        }

        string tmp1 = xoay_trai(s1);
        if(se.find(tmp1) == se.end()){
            q.push({tmp1, step+1});
            se.insert(tmp1);
        }

        string tmp2 = xoay_phai(s1);
        if(se.find(tmp2) == se.end()){
            q.push({tmp2, step+1});
            se.insert(tmp2);
        }
    }
}

void solve() {
    start = "";
    for(int i=0; i<10; i++){
        int x;
        cin >> x;

        start += string(1, x + '0');
    }

    // cout << start << endl;
    se.clear();
    se.insert(start);
    bfs();
    // for(auto x : se) cout << x << endl;
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