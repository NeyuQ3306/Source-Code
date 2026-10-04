#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MAXN = 1e7;

/* Ý tưởng: 

*/

// int n,k, a[20], final;
// void ktao(){
//     for(int i=1; i<=n; i++){
//         a[i] = 0;
//     }
// }

// bool check(){
    
// }

// void sinh(){
//     int i = n;
//     while(i >= 1 && a[i] == 1){
//         a[i] = 0;
//         --i;
//     }

//     if(i==0)
//         final = 1;

//     else
//         a[i] = 1;
// }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        ll sum = 0;
        for(char c : s)
            sum += (c - '0');

        if(sum == 0)
            for(int i=0; i<s.size(); i++)
                cout << '1';

        else{
            int i = s.size()-1;
            while(i>=0 && s[i] == '0'){
                s[i] = '1';
                --i;
            }

            s[i] = '0';

            cout << s;
        }

        cout << endl;

    }
    
    return 0;
}