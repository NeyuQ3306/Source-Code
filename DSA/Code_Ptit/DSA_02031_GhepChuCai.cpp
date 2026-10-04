#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng:  

*/


int n,m,k,X[100], a[100], used[100];
// int cheoxuoi[100], cheonguoc[100], cot[100];
vector<string> res;
ll ans = 0;

bool nguyenam(char c){
    if(c == 'A' || c == 'E')
        return true;

    return false;
}

void inkq(){
    string tmp = "";
    for(int i=1; i<=n; i++)
        tmp += (char)(64 + X[i]);

    bool check = true;
    for(int i=0; i<tmp.size(); i++){
        if(nguyenam(tmp[i])){
            if(i!=0  && i != tmp.size()-1){
                if(!nguyenam(tmp[i-1]) && !nguyenam(tmp[i+1]))
                    check = false;
            }

        }
    }
    

    if(check)
        cout << tmp << endl;  

    
}

void Try(int i){
    for(int j=1; j<=n; j++){
        if(used[j] == 0){
            X[i] = j;
            used[j] = 1;

            if(i == n)
                inkq();
            else
                Try(i+1);

            used[j] = 0;
        }
    }
}


void solve(){
    char c;
    cin >> c;

    n = c - 'A' + 1;
    Try(1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}