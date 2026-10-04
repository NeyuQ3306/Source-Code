#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Bài này ta có thể làm theo 2 cách
Cách 1: Tham lam, với mỗi vị trí i đang xét ta tìm vị trí j > i sao cho s[j] > s[i] và thực hiện
swap và --k 
- Lưu ý ở cách này sẽ có test sai nếu đằng sau i có nhiều giá trị a[j] giống nhau (đã lớn nhất) thì
thực hiện swap các vị trí khác nhau sẽ gây ảnh hưởng cho i sau
- Nhưng với bài này trên codePtit thì ac full test, đpt O(n^2)

Cách 2: Quay lui theo giá trị và cắt nhánh để giảm độ phức tạp O(n! / cắt nhánh)
- Với mỗi vị trí i, ta quay lui với mọi giá trị a[j] (vị trí j > i) 
và a[j] > a[i] lớn nhẩt (xử lí nhược điểm của cách tham lam trên nếu gặp test như vậy)
- Tham số của hàm Try(string s, int k, int i)

*/

string ans = ""; // biến ans lưu kq bài toán

void Try(string s, int k, int i){
    if(s > ans) ans = s; // nếu cấu hình này lớn hơn thì gán cho ans
    if(k==0 || i == s.size()) return; // hết bước swap hoặc đã đi hết các phần tử

    // ta tìm giá trị aj lớn nhất với aj > ai
    char max_digit = s[i];
    for(int j=i+1; j<s.size(); j++){
        if(s[j] > max_digit) max_digit = s[j];
    }

    // nếu tồn tại thì đây là 1 lượt swap, nếu ko có cải thiện thì vẫn phải tiếp tục cho vị trí tiếp
    if(max_digit == s[i]){
        Try(s, k, i+1);
        return;
    }

    // Đây là bước quay lui, ta swap tất cả các vị trí max_digit
    for(int j=s.size()-1; j>i; j--){
        if(s[j] == max_digit){
            swap(s[i], s[j]);
            // tiếp tục quay lui giá trị cho phần tử tiếp theo
            Try(s,k-1,i+1);
            // Backtrack: trả lại điểm rẽ nhánh
            swap(s[i],s[j]);
        }
    }
}

void solve() {
    ans.clear();
    int k;
    string s;
    cin >> k >> s;

    Try(s,k,0);
    cout << ans << endl;
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