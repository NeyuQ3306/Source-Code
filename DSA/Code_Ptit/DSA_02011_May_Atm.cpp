#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/
int n,s,x[101],a[101];
int res = 1e9;

void ql(int i, int bd, int sum){
    for(int j=bd; j<=n; j++){
        if(sum + a[j] <= s){
            // biến bd được dùng thay used vì mỗi phần tử chỉ dùng 1 lần
            x[i] = a[j];
            if(sum + a[j] == s) res = min(res, i);
            else ql(i+1,j+1,sum+a[j]);
        }

        else return; // rơi vào câu lệnh này thì kết thúc cả hàm ql luôn 
    }
}

void solve() {
    cin >> n >> s;
    memset(x,0,sizeof(x));
    res = 1e9;

    for(int i=1; i<=n; i++) cin >> a[i];
    // sort tăng dần để cắt nhánh tối ưu
    sort(a+1,a+n+1);
    ql(1,1,0);

    if(res == 1e9) cout << "-1\n";
    else cout << res << endl;
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