#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng:

*/

void solve() {
    int sum = 0, sl = 0;
    cin >> sum >> sl;

    if(9 * sl < sum || (sum == 0 && sl > 1)){
        cout << "-1" << endl;
        return;
    }

    string res(sl,'0');
    for(int i=res.size()-1; i>=0; i--){
        if(sum > 9){
            res[i] = '9';
            sum -= 9;
        }

        else{
            if(i != 0){
                res[i] = sum - 1 + '0';
                res[0] = '1';
                break;
            }

            else{
                res[0] = sum + '0';
            }
        }
    }

    cout << res << endl;
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