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

/* Ý tưởng: Ta coi trạng thái của mảng 2 chiều là 1 string
*/

unordered_set<string> se;
string s1,s2;

string xoay_trai(string s){
    string res = s;

    res[0] = s[3];
    res[1] = s[0];
    res[4] = s[1];
    res[3] = s[4];

    return res;
}

string xoay_phai(string s){
    string res = s;

    res[1] = s[4];
    res[2] = s[1];
    res[4] = s[5];
    res[5] = s[2];

    return res;
}

void bfs(){
    queue<pair<string,int>> q;
    q.push({s1,0});
    se.insert(s1);

    while(!q.empty()){
        auto t = q.front();
        q.pop();

        string s = t.fi;
        int step = t.se;

        if(s == s2){
            cout << step << endl;
            return;
        }

        string left = xoay_trai(s);
        if(se.find(left) == se.end()){
            q.push({left, step + 1});
            se.insert(left);
        }

        string right = xoay_phai(s);
        if(se.find(right) == se.end()){
            q.push({right, step + 1});
            se.insert(right);
        }
    }
}

void solve() {
    se.clear();
    s1 = s2 = "";

    for(int i=1; i<=6; i++){
        int x;
        cin >> x;
        s1 = s1 + string(1, x + '0'); 
    }

    for(int i=1; i<=6; i++){
        int x;
        cin >> x;
        s2 = s2 + string(1, x + '0'); 
    }

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