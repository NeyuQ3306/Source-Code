#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = INT_MIN;
    for(char a = 'a'; a <= 'z'; a++){
        for(char b = 'a'; b <= 'z'; b++){
            if(a == b) continue;
            int cntb = 0;
            for(char c : s){
                if(c == b) ++cntb;
            }

            bool hasb = false;
            int diff = 0;
            for(char c : s){
                if(c != a && c != b) continue;
                if(c == a) ++diff;
                if(c == b){
                    --diff;
                    --cntb;
                    hasb = true;
                }

                if(hasb) ans = max(ans, diff);

                if(diff < 0 && cntb > 0){
                    diff = 0;
                    hasb = false;
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
              
    while(t--){
       solve(); 
    }
    return 0;
}