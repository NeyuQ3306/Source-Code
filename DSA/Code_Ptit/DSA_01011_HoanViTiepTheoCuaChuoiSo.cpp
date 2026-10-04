#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MAXN = 1e7;

/* Ý tưởng: 

*/

// int n, k, a[50], b[50], final;
// void ktao(){
//     for(int i=1; i<=k; i++){
//         a[i] = i;
//     }
// }

// bool check(){
    
// }

// void sinh(){
    
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
        int stt;
        string s;
        cin >> stt >> s;

        int i = s.size()-2;
        while(i>=0 && (s[i] - '0') >= (s[i+1] - '0'))
            --i;

        if(i<0)
            cout << stt << " BIGGEST\n";

        else{
            int j=s.size()-1;
            while(s[i] - '0' >= s[j] - '0')
                --j;

            swap(s[j], s[i]);

            reverse(s.begin()+i+1, s.end());
            cout << stt << " " << s << endl;
        }

        


    }
    
    return 0;
}