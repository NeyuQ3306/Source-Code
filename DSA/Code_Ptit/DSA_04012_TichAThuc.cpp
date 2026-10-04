#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

/* Ý tưởng: Nhân đa thức
- Vì bài này cho dữ liệu bé nên ta có thể nhân trực tiếp 2 vòng for
- Nếu dữ liệu m,n > 10^4 thì phải dùng FFT
- Đề cho ta m,n là số lượng phần tử của đa thức thì tương ứng bậc của 
đa thức đó là m-1, n-1
- Đa thức kq sẽ có bậc là (m-1)+(n-1) = m+n-2 và số lượng phần tử là m+n-2+1 = m+n-1
*/




int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int m,n;
        cin >> m >> n;

        vector<int> P(m);
        vector<int> Q(n);

        for(int i=0; i<m; i++)
            cin >> P[i];
        for(int i=0; i<n; i++)
            cin >> Q[i];

        vector<int> R(m+n-1,0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                R[i+j] += P[i] * Q[j];
        }

        for(int x : R)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}
