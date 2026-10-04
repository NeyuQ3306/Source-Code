#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng: Xuất phát từ bài toán in ra các dãy con (đúng thứ tự xuất hiện) của mảng a sao cho
dãy con đó tăng dần
- Bài này ta chỉ thêm điều kiện sum lẻ là được, backtrack lại cho i các value mới thì trả lại sum thời
điểm đó
- Code dãy con tăng dần:
void ql(int i, int bd){
    for(int j=bd; j<=n; j++){
        if(a[j] > x[i-1]){
            x[i] = a[j];

            if(i >= 2){
                for(int u=1; u<=i; u++) cout << x[u] << " ";
                cout << endl;
            }
            // tiếp tục xây dựng cho tới khi ko thoả mãn thì backtrack thử value khác
            ql(i+1,j+1);
        }
    }
}

*/
int n, x[101], a[101];
// vector<vector<int>> res;
set<vector<int>> res;

void ql(int i, int bd, int sum){
    for(int j = bd; j <= n; j++){
        x[i] = a[j];
        sum += a[j];

        if(sum % 2 == 1){
            vector<int> tmp;
            for(int u=1; u<=i; u++) tmp.push_back(x[u]);
            res.insert(tmp);
        }

        ql(i+1, j+1, sum);
        sum -= a[j];
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1, greater<int>()); 

    res.clear();
    ql(1, 1, 0);
    for(auto s : res){
        for(int x : s) cout << x << " ";
        cout << endl;
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