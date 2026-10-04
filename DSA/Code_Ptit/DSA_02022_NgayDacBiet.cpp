#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: 

*/

// int n, k, cnt, a[50], b[50], final;


// void ktao(){
//     for(int i=1; i<=k; i++){
//         a[i] = i;
//     }
// }

// bool check(){
//     ll sum = 0;
//     for(int i=1; i<=k; i++)
//         sum += a[i];

//     for(int i=0; i<=98; i++)
//         if(F[i] == sum)
//             return true;

//     return false;
// }

// void sinh(){
//     int i=k;
//     while(i>=1 && a[i] == n-k+i)
//         --i;

//     if(i==0)
//         final = 1;
//     else{
//         ++a[i];
//         for(int j=i+1; j<=k; j++)
//             a[j] = a[j-1] + 1;
//     }
// }


string X(8,'0');
vector<string> ress;

void inkq(){
    int d,m,y;
    d = stoi(X.substr(0,2));
    m = stoi(X.substr(2,2));
    y = stoi(X.substr(4));

    if(d > 0 && d <= 31 && m > 0 && m < 12 && y >= 2000){
        string res;
        if(d < 10)
            res += "0" + to_string(d);
        else
            res += to_string(d);

        res += "/";

        if(m < 10)
            res += "0" + to_string(m);
        else
            res += to_string(m);

        res += "/";
        res += to_string(y);

        ress.push_back(res);
    }
}

void Try(int i){
    for(int j=0; j<=1; j++){
        if(j==0)
            X[i] = '0';
        else
            X[i] = '2';

        if(i==7)
            inkq();
        else
            Try(i+1);
    }
}

void solve(){
    Try(0);

    sort(ress.begin(), ress.end());
    for(auto x : ress)
        cout << x << endl;
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