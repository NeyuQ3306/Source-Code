#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;

/* Ý tưởng: 

*/


int n,k,X[100];
vector<string> v(100);

// int cnt = 0;

// bool check(int n){
//     for(int i=2; i<=sqrt(n); i++)
//         if(n%i == 0)
//             return false;

//     return n>1;
// }

void inkq(){
    for(int i=1; i<=k; i++){
        cout << v[X[i]] << ' ';
    }

    cout << endl;
}

void Try(int i){
    for(int j = X[i-1]+1; j <= n-k+i; j++){
        X[i] = j;

        if(i == k){
            inkq();
        }

        else{
            Try(i+1);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    string line;

    cin.ignore();
    getline(cin, line);

    stringstream ss(line);
    set<string> se;
    string token;

    while(ss >> token)
        se.insert(token);

    n = se.size();

    int idx = 1;
    for(string x : se)
        v[idx++] = x;

    Try(1);


    return 0;
}