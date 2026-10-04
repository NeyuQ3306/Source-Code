#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
ll n, m, cnt, k;
ll a[MAXN], b[MAXN], c[MAXN];
vector<string>res;
bool check_final = false;

/* Ý tưởng: Bài này dùng map sẽ wa vì yêu cầu của đề k phải là tìm
tập giao của 3 tập đã cho mà là in các phần tử xuất hiện ở cả 3 dãy số
- Ví dụ:
1 5 5 10 20 40 80
2 3 5 5 12 14
5 5 5 6 7 8 9 10
thì output mong muốn là: 5 5 10 
- Thì dùng map nó sẽ bị loại đi phần tử trùng làm sai đáp án, ta dùng
3 con trỏ để duyệt 3 tập vì đã là tập được sắp xếp
*/


void solve() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int j=0; j<m; j++)
        cin >> b[j];
    for(int x=0; x<k; x++)
        cin >> c[x];

    vector<ll> res;
    int i = 0, j = 0, x = 0;
    while(i<n && j<m && x<k){
        if(a[i] == b[j] && b[j] == c[x]){
            res.push_back(a[i]);
            ++i,++j,++x;
        }

        else if(a[i] < b[j])
            ++i;
        else if(b[j] < c[x])
            ++j;
        else
            ++x;
    }

    if(res.empty())
        cout << "-1" << endl;
    else{
        for(int x : res)
            cout << x << " ";
        cout << endl;
    }
    
}

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
        solve();
    }

    return 0;
}