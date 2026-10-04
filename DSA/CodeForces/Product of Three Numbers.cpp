#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Đề bài: Cho 1 số N hỏi có cách nào phân tích N = a*b*c sao cho a,b,c >= 2 hay ko? Nếu có
ít ra bắt cứ cách phân tích nào, ngược lại in ra NO

Link: https://codeforces.com/problemset/problem/1294/C?utm_source=chatgpt.com
*/

/* Ý tưởng: Xuất phát từ việc muốn phân tích thừa số nguyên tố của N có p ước
- Nếu p >= 3 thì chắc chắn có thể phân tích: N = 2^3 * 3^1 * 5^2 thì bản thân nó đã là 3 số khác nhau
- Nếu p = 2 thì tổng số mũ phải >= 4: N = 2^2 * 3^2 = 2 * 3 * 6
    + Nếu số mũ < 4: N = 2*2 * 3 thì chắc chắn ko thể phân tích được
- Nếu p = 1 thì tổng số mũ phải >= 6: N = 2^6 = 2 * 2^2 * 2^3

=> Tư tưởng tham lam ở đây là ta muốn số mũ càng lớn càng dễ phân tích thì cơ số càng nhỏ, muốn
cơ số nhỏ thì phải là số nguyên tố => phân tích tso nguyên tố
*/

void solve() {
    int n;
    cin >> n;

    int tmp = n;

    bool check = false;
    int cnt_e = 0, cnt_p = 0;
    vector<pair<int,int>> v;
   
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            ++cnt_p;
            int cnt_mu = 0;

            while(n%i==0){
                ++cnt_mu;
                ++cnt_e;
                n /= i;
            }

            v.push_back({i,cnt_mu});
        }
    }

    if(n != 1){
        ++cnt_p;
        ++cnt_e;

        v.push_back({n, 1});
    }

    if(cnt_p >= 3 || cnt_p == 2 && cnt_e >= 4 || cnt_p == 1 && cnt_e >= 6){
        cout << "YES" << endl;
        if(cnt_p >= 3){
            cout << (ll)pow(v[0].first, v[0].second) << " " 
                 << (ll)pow(v[1].first, v[1].second) << " "
                 << tmp / ((ll)pow(v[0].first, v[0].second) *  (ll)pow(v[1].first, v[1].second))
                 << endl;
        }

        else if(cnt_p == 2){
            cout << v[0].first << " "
                 << v[1].first << " "
                 << tmp / (v[0].first * v[1].first)
                 << endl;
        }

        else if(cnt_p == 1){
            cout << v[0].first << " "
                 << (ll)pow(v[0].first, 2) << " "
                 << tmp / (v[0].first * (ll)pow(v[0].first, 2))
                 << endl;
        }
    }

    else cout << "NO" << endl;
    
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