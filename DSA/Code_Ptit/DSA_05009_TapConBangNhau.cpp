#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
/* Ý tưởng:  Bài này test lỏng điều kiện cần để mảng a có thể chia thành 2 tập bằng nhau là
tổng mảng a phải là số chẵn: Lẻ + Lẻ = Chẵn, Chẵn + Chẵn = Chẵn
void solve(){
    memset(a,0,sizeof(a));
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    ll sum = accumulate(a,a+n,1ll*0);
    cout << (sum%2==0 ? "YES\n" : "NO\n");
    
}
- Nhưng thoả điều kiện đủ chưa chắc đã chia được thành 2 tập con bằng nhau
VD: 9 8 5, tổng bằng 22 chẵn nhưng k thể chia thành 2 tập bằng nhau được
*/


int n, sum, a[101], x[101];
bool ok;

void ql(int i, int bd, int s){
    if(ok) return;
    for(int j=bd; j<=n; j++){
        if(s + a[j] <= sum){
            x[i] = a[j];

            if(s + a[j] == sum) ok = true;
            else ql(i+1,j+1,s+a[j]);
        }
        else return;
    }
}

void solve(){
    ok = false;
    sum = 0;
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));

    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);

    sum = accumulate(a+1,a+n+1,0);
    // check đk cần tối ưu tgian
    if(sum % 2 == 1) cout << "NO\n";

    else{
        // ta đi tìm xem có tập con nào có tổng = sum/2 ko là được
        sum /= 2;
        ql(1,1,0);
        cout << (ok ? "YES\n" : "NO\n");
    }
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