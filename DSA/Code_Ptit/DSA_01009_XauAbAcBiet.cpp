#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MAXN = 1e7;

/* Ý tưởng: 

*/

int n, k, a[100], b[100], final;
void ktao(){
    for(int i=1; i<=n; i++){
        a[i] = 0;
    }
}

bool check(){
    int cnt = 0;
    int len = 0;

    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            ++len;
        } else {
            if(len == k) ++cnt;
            len = 0;
        }
    }

    if(len == k) ++cnt; // đoạn cuối

    return cnt == 1;
}

void sinh(){
    int i=n; 
    while(i>=1 && a[i] == 1){
        a[i] = 0;
        --i;
    }

    if(i==0)
        final = 1;
    else
        a[i] = 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    ktao();

    vector<string> v;
    while(!final){
        if(check()){
            string tmp;
            for(int i=1; i<=n; i++){
                tmp += (a[i] == 0 ? "A" : "B");
            }

            v.push_back(tmp);
        }

        sinh();
    }

    cout << v.size() << endl;
    for(int i=0; i<v.size(); i++)
        cout << v[i] << endl;
    
    return 0;
}