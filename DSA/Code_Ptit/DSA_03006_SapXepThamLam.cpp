#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN], b[MAXN], dp[MAXN];

/* Ý tưởng: Ta thực hiện sort mảng a có mảng A, sắp xếp tham lam được nếu
a[i] = A[n-i-1] nghĩa là phần tử này thực hiện phép đối xứng qua vị trí n/2
hoặc
a[i] = A[i] nếu nó vẫn là vị trí ban đầu
=> ko thỏa mãn 2 điều kiện này thì k sắp xếp được 
*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) b[i] = a[i];
        sort(b, b+n);
        bool ok = true;
        for(int i=0; i<n; i++){
            if(a[i] != b[i] && a[i] != b[n-1-i]){
                ok = false;
                break;
            }
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}