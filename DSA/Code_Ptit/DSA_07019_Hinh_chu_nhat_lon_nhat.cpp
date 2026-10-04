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

/* Ý tưởng: Với mỗi cột có chiều cao a[i] ta xét tất cả các hình chữ nhật có chiều cao a[i]
- Mở rộng sang trái cho tới khi gặp vị trí đầu tiên có a[j] < a[i] thì dừng
- Mở rộng sang phải cho tới khi gặp vị trí đầu tiên có a[j] < a[i] thì dừng
-> tính toàn chiều dài tối đa có thể mở rộng
-> nếu ko có vị trí đầu tiên bên phải, bên trái nhỏ hơn thì chiều dài = n

*/

void solve() {
    int n;
    cin >> n;

    int a[n];
    for(int &x : a) cin >> x;

    // mảng left: chỉ số phần tử nhỏ hơn đầu tiên bên trái
    // mảng right: chỉ số phần tử nhỏ hơn đầu tiên bên phải
    int left[n], right[n];
    stack<int> st1,st2;
    
    for(int i=0; i<n; i++){
        if(st1.empty()){
            st1.push(i);
        }

        else{
            while(!st1.empty() && a[i] < a[st1.top()]){
                right[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }
    }

    while(!st1.empty()){
        right[st1.top()] = n;
        st1.pop();
    }

    for(int i=n-1; i>=0; i--){
        if(st2.empty()){
            st2.push(i);
        }

        else{
            while(!st2.empty() && a[i] < a[st2.top()]){
                left[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }
    }

    while(!st2.empty()){
        left[st2.top()] = -1;
        st2.pop();
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, 1ll * a[i] * (right[i] - left[i] - 1));
    }

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