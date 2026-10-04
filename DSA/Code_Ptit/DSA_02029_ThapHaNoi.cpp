#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: 

*/

void chuyen(char nguon, char dich){
    cout << nguon << " -> " << dich << endl;
}

void thaphanoi(int n, char nguon, char trgian, char dich){
    if(n == 1)
        chuyen(nguon, dich);
    else{
        thaphanoi(n-1, nguon, dich, trgian);
        chuyen(nguon, dich);
        thaphanoi(n-1, trgian, nguon, dich);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    char nguon = 'A', trgian = 'B', dich = 'C';
    thaphanoi(n, nguon, trgian, dich);

    return 0;
}