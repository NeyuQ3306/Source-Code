#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Chuyển từ mã gray sang mã nhị phân, ta có mã binary và gray
- binary[1] = gray[1]
- binary(i>1) = binary(i-1) ^ gray[i]

- Chú ý: XOR giữa 2 kí tự thì sẽ trả về mã ASCII gây sai output
*/

string Convert_to_binary(string s){
    string res = "";
    res += s[0];

    for(int i = 1; i < s.size(); i++){
        char bit = ((res[i-1] - '0') ^ (s[i] - '0')) + '0';
        res += bit;
    }

    return res;
}

void solve() {
    string gray;
    cin >> gray;

    cout << Convert_to_binary(gray) << endl;
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