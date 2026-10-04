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

/* Ý tưởng: Biểu diễn inOrder của 1 cây BST phải là 1 dãy tăng dần
*/

void solve() {
    int n;
    cin >> n;

    int a[n];
    for(int &x : a) cin >> x;

    for(int i=0; i<n-1; i++){
        if(a[i] >= a[i+1]){
            cout << 0 << endl;
            return;
        }
    }

    cout << 1 << endl;
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