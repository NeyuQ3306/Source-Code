#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define sz size
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: Ta xét mọi cặp kí tự (a,b) coi a là kí tự có tần suất xuất hiện
lớn nhất và b là kí tự có tần suất xuất hiện ít nhất trong 1 xâu con liên tiếp
nào đó
- Bài toán trở thành tìm dãy con liên tiếp có tổng lớn nhất - Kadane
- Bài toán dãy con có tổng lớn nhất ta duyệt từ trái sang phải:
    Duy trì 1 biến curSum, tại 1 vị trí nếu curSum < 0 thì reset về 0
    Nếu curSum > 0 ta so sánh với ans để lấy kq tốt nhất
=> Đpt chỉ mất O(n)

- Liên hệ với bài này: Với mỗi cặp kí tự (a,b) ta coi khi duyệt từ trái sang phải
gặp kí tự a thì coi là 1 và kí tự b coi là -1
    Biến curSum sẽ tương ứng là diff(fre(a) - fre(b))
    Nếu biến diff < 0 và phía sau còn gặp b để có thể tăng diff ta reset về 0
    => Giữ đoạn đằng sau có thể tốt hơn
    Phải duy trì thêm 1 biến check xem dãy con đang xét có còn kí tự b ko
vì đề ycau fre(b) > 0
*/

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for(char a = 'a'; a <= 'z'; a++){
        for(char b = 'a'; b <= 'z'; b++){
            if(a == b) continue;

            // diff chính là dãy con có tổng lớn nhất
            int diff = 0, cnt_b = 0;
            bool check = false;

            // ta phải duy trì biến cnt_b để biết ở sau có còn gặp kí tự b hay ko
            // nếu cnt_b > 0 và diff < 0 ta mới được reset vì đoạn trước đang tệ ko cần giữ
            for(char c : s){
                if(c == b) ++cnt_b;
            }

            for(char c : s){
                // nếu ko phải cặp kí tự đang xét coi là phần tử 0
                if(c != a && c != b) continue;

                if(c == a) ++diff;
                else{
                    --diff;
                    --cnt_b;
                    // biến check để biết đoạn đang xét có tồn tại ít nhất 1 kí tự b ko
                    check = true;
                }

                // Đến đây là xong 1 lần bài toán Kadane với cặp kí tự (a,b)
                if(check) ans = max(ans, diff);
                if(diff < 0 && cnt_b > 0){
                    diff = 0;
                    check = false;
                }
            }
        }
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