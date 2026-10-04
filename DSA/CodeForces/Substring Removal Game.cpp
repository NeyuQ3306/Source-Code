#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Đề bài: Cho 1 xâu nhị phân, có 2 người chơi A và B, A đi trước và đến B cứ lần lượt như thế cho
tới khi xâu rỗng. Ở mỗi bước, người chơi có thể chọn xóa đi 1 xâu con gồm các kí tự giống nhau liền kề
, sau khí xóa thì phần trái và phải chập lại với nhau thành xâu mới. Mục tiêu là người chơi phải xóa đi 
được càng nhiều số 1 càng tốt, biết cả 2 đều chơi tối ưu. Hãy tìm số lưọng tối đa của người A?
*/

/* Ý tưởng: Đây là dạng string game, do cả 2 đều chơi tối ưu thì ta tham lam bằng cách ở mỗi lượt
đều chọn xâu con toàn 1 dài nhất để xóa đi là được
*/

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    vector<int> len_1;
    int cur_len = 0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '1'){
            ++cur_len;
        }

        else{
            if(cur_len != 0)  len_1.push_back(cur_len);
            cur_len = 0;
        }
    }

    if(cur_len != 0) len_1.push_back(cur_len);

    ll ans = 0;
    sort(len_1.begin(), len_1.end(), greater<int>());
    for(int i=0; i<len_1.size(); i+=2){
        // cout << len_1[i] << " ";
        ans += len_1[i];
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
              
    while(t--){
       solve(); 
    }
    return 0;
}