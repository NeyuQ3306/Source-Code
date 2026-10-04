#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN], X[MAXN];

/* Ý tưởng:  Chuyển đổi số nhị phân sang mã gray
- Giữ nguyên bit trọng số cao nhất
- Từ bit thứ 2 từ bên trái ta lấy bi ^ b(i-1) (XOR) để tính bit thứ i 
của mã gray
- In từ trái qua phải (1->n)
*/

void inkq(){
    cout << X[1];
    for(int i=2; i<=n; i++){
        cout << (X[i] ^ X[i-1]);
    }
    cout << " ";
}

void Try(int i){
    for(int j=0; j<=1; j++){
        X[i] = j;
        
        if(i == n) inkq();
        else Try(i+1);
    }
}

void solve() {
    cin >> n;
    Try(1);
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