#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

/* Ý tưởng: 
*/




int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    stack<int> st;

    while(t--){
        string s;
        cin >> s;

        if(s == "PUSH"){
            int x; 
            cin >> x;
            st.push(x);
        }

        if(s == "POP")
            if(!st.empty())
                st.pop();

        if(s == "PRINT"){
            if(st.empty())
                cout << "NONE" << endl;
            else
                cout << st.top() << endl;
        }
    }

    return 0;
}
