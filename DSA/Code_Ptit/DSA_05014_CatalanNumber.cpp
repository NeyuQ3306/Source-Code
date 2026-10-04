#include <bits/stdc++.h>
using namespace std;

using Big = vector<int>;
const int BASE = 10;

Big mul(Big a, int b){
    int carry = 0;
    for(int &x : a){
        carry += x * b;
        x = carry % BASE;
        carry /= BASE;
    }
    while(carry){
        a.push_back(carry % BASE);
        carry /= BASE;
    }
    return a;
}

Big divi(Big a, int b){
    int carry = 0;
    for(int i = a.size()-1; i >= 0; i--){
        carry = carry * BASE + a[i];
        a[i] = carry / b;
        carry %= b;
    }
    while(a.size() > 1 && a.back() == 0) a.pop_back();
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        Big res = {1};
        for(int i = 1; i <= n; i++){
            res = mul(res, n + i);
            res = divi(res, i);
        }
        res = divi(res, n + 1);

        for(int i = res.size()-1; i >= 0; i--)
            cout << res[i];
        cout << '\n';
    }
}
