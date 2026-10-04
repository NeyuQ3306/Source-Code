#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Chuyển từ mã nhị phân sang gray, giống bài 01012 - MÃ Gray1
- Ta có công thức chuyển đổi:
gray[1] = binary[1]
gray[i>1] = binary[i] ^ binary[i-1]
*/

string Convert_to_gray(string b){
    string res = "";
    res += b[0];

    for(int i=1; i<b.size(); i++){
        char bit = ((b[i-1] - '0') ^ (b[i] - '0')) + '0';
        res += bit;
    }
    
    return res;
}

void solve() {
    string binary;
    cin >> binary;

    cout << Convert_to_gray(binary) << endl;
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