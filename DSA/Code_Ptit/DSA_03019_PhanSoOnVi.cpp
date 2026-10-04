#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Phân số đơn vị - Phân số có tử bằng 1
- Mục tiêu của bài này là phân tích phân số P đã cho thành các phân số đơn vị sao cho số hạng tử là
ít nhất
- Muốn số hạng tử là ít nhất thì mỗi hạng tử phải là lớn nhất có thể, ta thực hiện lặp phân tích:
P = 1/x + P', muốn tồn tại 1/x thì 1/x <= P hay x >= 1/P
Cứ lặp 1 bước như thế là ta được 1 hạng tử 1/x, P = P - 1/x = P' ta tiếp tục lặp cho P' cho tới khi
P = 0 nghĩa là đã phân tích hết
*/

ll gcd(ll a, ll b){
    while(b){
        ll tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

ll lcm(ll a, ll b){
    return a/gcd(a,b) * b;
}

struct PhanSo{
    ll tu,mau;
    void rutgon(){
        ll k = gcd(tu,mau);
        tu /= k;
        mau /= k;
    }

    void in(){
        cout << tu << "/" << mau;
    }

    friend PhanSo operator - (PhanSo a, PhanSo b){
        PhanSo hieu;
        ll bc = lcm(a.mau, b.mau);
        hieu.mau = bc;
        hieu.tu = bc/a.mau * a.tu - bc/b.mau * b.tu;
    
        hieu.rutgon();
        return hieu;
    }
};



void solve() {
    PhanSo P;
    cin >> P.tu >> P.mau;

    while(P.tu != 0){
        ll x = ceil(P.mau * 1.00 / P.tu);
        PhanSo tmp;
        tmp.tu = 1, tmp.mau = x;
        tmp.in();
        P = P - tmp;

        if(P.tu != 0) cout << " + ";
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