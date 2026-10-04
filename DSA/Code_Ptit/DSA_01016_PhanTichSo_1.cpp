#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: Phân hoạch n bằng sinh kế tiếp
- Cấu hình đầu tiên: n
- Cấu hình cuối cùng: 1 1 1 1 1 ... (n số 1)
- Phương pháp sinh:
    + Ở cấu hình hiện tại, tìm vị trí phần tử đầu tiên từ bên phải sang khác 1
nếu i==0 nghĩa là cấu hình cuối cùng, i != 0 thì ta giảm a[i] đi 1 đơn vị
    + Tính d là số lượng đơn vị còn thiếu để phân hoạch đủ số n khi đã biết các
số hạng a1 a2 ... ai, d = cnt - i + 1;
    + Ta biểu diễn các số hạng còn thiếu từ vị trí i+1 qua a[i] bằng cách tính 
q = d/a[i] : số lượng số hạng có thể biểu diễn theo a[i]
r = d%a[i] : phần dư còn lại nếu k biểu diễn hết theo a[i]

*/


int n,m,k,X[100], a[100], used[100];
int cnt = 0;
bool check_final = false;
ll ans = 0;


void ktao(){
    cnt = 1, a[1] = n;
}

void sinh(){
    // tìm vị trí phần tử đầu tiên khác 1
    int i = cnt; // cnt là số lượng số hạng của cấu hình hiện tại
    while(i>=1 && a[i] == 1)
        --i;

    if(i==0)
        check_final = true;

    else{
        --a[i];
        int d = cnt - i + 1;
        cnt = i;
        int q = d/a[i], r = d%a[i];

        if(q != 0){
            for(int j=1; j<=q; j++){
                ++cnt;
                a[cnt] = a[i];
            }
        }

        if(r != 0){
            ++cnt;
            a[cnt] = r;
        }
    }
}


void solve(){
    cnt = 0;
    memset(a,0,sizeof(a));
    check_final = false;

    cin >> n;
    ktao();

    while(!check_final){
        cout << "(";
        for(int i=1; i<=cnt; i++){
            if(i != cnt)
                cout << a[i] << " ";
            else
                cout << a[i] << ") ";
        }

        sinh();
    }
    cout << endl;
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