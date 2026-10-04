#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Đây là bài tổng quát của Sắp xếp xâu kí tự sao cho ko có
2 kí tự giống nhau đứng cạnh nhau
- Nghĩa là bài toán con sao cho cứ cách nhau 1 vị trí (2 đơn vị khoảng cách) hay
dễ hiêu là a ở chỉ số 1 thì a tiếp theo gần nhất là vị trí 1+2 = 3
- Lời giải của bài toán con này là với len chẵn thì tối đa max_fre là len/2 và len 
lẻ là (len+1)/2; nếu max_fre > giới hạn đó thì ko thể sắp xếp
- Bài toán tổng quát với khoảng cách là d ta có công thức tương tự là
max_fre <= (len/d) + 1
- Hình dung đơn giản ví dụ có mảnh đất dài 10m, trồng mỗi cây cách nhau 3m thì
|. . | . . | . .  | thì có tối đa là 10/3 + 1 = 4 cây
*/

void solve() {
    int d;
    string s;
    cin >> d >> s;

    int dem[256] = {0};
    int max_fre = 0;
    for(char c : s){
        dem[c]++;
        max_fre = max(max_fre, dem[c]);
    }

    if(max_fre <= (s.size() / d) + 1) cout << "1" << endl;
    else cout << "-1" << endl;
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