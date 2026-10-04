#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Dãy Bitonic hay dãy Moutain có nửa đầu tăng và nửa sau giảm
- Để tìm dãy bitonic có tổng lớn nhất ta xét tất cả các dãy bitonic với đỉnh là i, tính tổng dãy con
tăng dài nhất ở bên trái và tổng dãy con giảm dài nhất ở bên phải
- Tổng dãy con giảm dài nhất chính là duyệt ngược lại tính tổng dãy con tăng dài nhất

*/


void solve() {
    int n;
    cin >> n;
    
    int a[n+1], T[n+1], G[n+1];
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=1; i<=n; i++){
        T[i] = a[i];
        for(int j=1; j<i; j++){
            if(a[i] > a[j]) T[i] = max(T[i], T[j] + a[i]);
        }
    }

    for(int i=n; i>=1; i--){
        G[i] = a[i];
        for(int j=n; j>i; j--){
            if(a[j] < a[i]) G[i] = max(G[i], G[j] + a[i]);
        }
    }

    int res = 0;
    for(int i=1; i<=n; i++){
        res = max(res, T[i] + G[i] - a[i]);
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