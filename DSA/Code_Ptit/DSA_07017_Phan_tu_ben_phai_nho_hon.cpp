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

/* Ý tưởng: Tìm phần tử đầu tiên nhỏ hơn bên phải của phần tử đầu tiên lớn hơn bên phải
- Ta tìm mảng NG lưu chỉ số của phần tử đầu tiên bên phải lớn hơn a[i]
- Tìm mảng NS lưu giá trị của phần tử đầu tiên bên phải nhỏ hơn a[i]
=> Khi muốn truy xuất phần tử đầu tiên nhỏ hơn bên phải của phần tử đầu tiên lớn hơn bên
phải của phần tử a[i] thì cần cout ra NS[NG[i]]
*/

void solve() {
    int n;
    cin >> n;

    int a[n], NG[n], NS[n];
    for(int &x : a) cin >> x;

    stack<int> st1;
    for(int i=0; i<n; i++){
        if(st1.empty()){
            st1.push(i);
        }

        else{
            while(!st1.empty() && a[i] > a[st1.top()]){
                NG[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }
    }

    while(!st1.empty()){
        NG[st1.top()] = -1;
        st1.pop();
    }

    stack<int> st2;
    for(int i=0; i<n; i++){
        if(st2.empty()){
            st2.push(i);
        }

        else{
            while(!st2.empty() && a[i] < a[st2.top()]){
                NS[st2.top()] = a[i];
                st2.pop();
            }
            st2.push(i);
        }
    }

    while(!st2.empty()){
        NS[st2.top()] = -1;
        st2.pop();
    }

    // for(int x : NG) cout << x << " ";
    // cout << endl;
    // for(int x : NS) cout << x << " ";

    for(int x : NG){
        if(x == -1) cout << -1 << " ";
        else cout << NS[x] << " ";
    }
    cout << endl;
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