#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
bool check_final = false;
int a[MAXN];


/* Ý tưởng:
*/
void ktao(){
    for(int i=1; i<=n; i++)
        a[i] = i;
}

void sinh(){
    int i=n-1;
    while(i >= 1 && a[i] > a[i+1])
        --i;

    if(i==0)
        check_final = true;

    else{
        int j = n;
        while(a[i] > a[j])
            --j;

        swap(a[i], a[j]);
        reverse(a+i+1, a+n+1);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    ktao();

    int cnt = 1;
    while(check_final == false){
        cout << cnt << ": ";
        for(int i=1; i<=n; i++)
            cout << a[i] << ' ';

        ++cnt;
        cout << endl;
        sinh();
    }
    return 0;
}