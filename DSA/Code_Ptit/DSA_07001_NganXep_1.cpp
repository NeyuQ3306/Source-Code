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

    string s;
    stack<int> st;

    while(cin >> s){
        if(s == "push"){
            int x;
            cin >> x;
            st.push(x);
        }

        if(s == "show"){
            if(st.empty())
                cout << "empty" << endl;
            else{
                stack<int> tmp = st;
                vector<int> v;

                while(!tmp.empty()){
                   v.push_back(tmp.top());
                   tmp.pop();
                }

                reverse(v.begin(),v.end());
                for(int x : v)
                    cout << x << " ";
                
                cout << endl;
            }
        }

        if(s == "pop")
            st.pop();
    }

    return 0;
}
