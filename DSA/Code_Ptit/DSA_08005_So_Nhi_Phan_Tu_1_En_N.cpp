#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/
vector<string> res;

void solve() {
    int n;
    cin >> n;

    queue<string> qu;
    qu.push("1");
    res.push_back("1");

    while(res.size() < 10000){

        string top = qu.front();
        qu.pop();
        qu.push(top + "0");
        qu.push(top + "1");

        res.push_back(top+"0");
        res.push_back(top+"1");
    }

    for(int i=0; i<n; i++){
        cout << res[i] << " ";
    }
    cout << endl;
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