#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 11;
ll n, m, k;
ll a[MAXN][MAXN], used[MAXN];
vector<int> X(MAXN);
vector<vector<int>> v;

/* Ý tưởng: Bài này với n<10 thì ta có thể dùng quay lui để sinh hoán vị cho mỗi hàng
- Độ phức tạp là O(n! * n), n! cho mỗi hoán vị và n hàng

*/

void inkq(){
    ll sum = 0;
    for(int i=1; i<=n; i++){
        sum += a[i][X[i]];
    }

    if(sum == k) v.push_back(X);
}

void Try(int i){
    for(int j=1; j<=n; j++){
        if(used[j] == 0){
            used[j] = 1;
            X[i] = j;

            if(i==n) inkq();
            else Try(i+1);

            used[j] = 0;
        }
    }
}

void solve() {
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }

    Try(1);
    cout << v.size() << endl;
    for(int i=0; i<v.size(); i++){
       for(int j=1; j<=n; j++) cout << v[i][j] << " ";
        cout << endl;
    }
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